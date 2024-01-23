// [1, 2, 3, 4] <- 줄인다고 가정
// 1 -> 0 : 1 -> 0 (-1)
// 2 -> 1 : 4 -> 1 (-3)
// 3 -> 2 : 9 -> 4 (-5)
// 4 -> 3 : 16 -> 9 (-7)
// 즉, 높은 수를 낮추는 것이 좋음.

class PriorityQueue {
    constructor() {
        this.queue = [];
        this.size = 0;
    }
    front() {
        if (this.size === 0) {
            return null;
        }
        return this.queue[0];
    }
    enqueue(x) {
        this.queue.push(x);
        let ptr = this.queue.length-1;
        this.size++;
        
        while (0 < ptr) {
            const parent = Math.floor((ptr - 1) / 2);
            if (this.queue[parent] < this.queue[ptr]) {
                [this.queue[parent], this.queue[ptr]] = [this.queue[ptr], this.queue[parent]];
                ptr = parent;
                continue;
            }
            break;
        }
    }
    dequeue() {
        if (this.size === 0) {
            return null;
        }
        this.size--;
        [this.queue[0], this.queue[this.queue.length-1]] = [this.queue[this.queue.length-1], this.queue[0]];
        const result = this.queue.pop();
        
        let ptr = 0;
        while (ptr < this.queue.length) {
            const left = ptr*2 + 1,
                  right = ptr*2 + 2;
            if (this.queue.length <= left) {
                break;
            }
            
            let biggest = left;
            if (right < this.queue.length && this.queue[left] < this.queue[right]) {
                biggest = right;
            }
            
            if (this.queue[ptr] < this.queue[biggest]) {
                [this.queue[ptr], this.queue[biggest]] = [this.queue[biggest], this.queue[ptr]];
                ptr = biggest;
                continue;
            } else {
                break;
            }
        }
        
        return result;
    }
}

function solution(n, works) {
    const pq = new PriorityQueue();
    
    works.forEach((work) => pq.enqueue(work));
    
    let count = n;
    
    while (0 < count && 0 < pq.size) {
        count = count - 1;
        const top = pq.dequeue();
        if (0 < top) {
            pq.enqueue(top - 1);
        }
    }
    
    if (0 < count) {
        return 0;
    }
    
    const answer = pq.queue.reduce((acc, cur) => acc + cur * cur, 0);
    
    return answer;
}