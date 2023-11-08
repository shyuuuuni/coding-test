class Node {
    constructor(x) {
        this.next = null;
        this.value = x;
    }
}
class Queue {
    constructor() {
        this.front = null;
        this.back = null;
        this.length = 0;
    }
    push(x) {
        const n = new Node(x);
        
        if (this.length === 0) {
            this.front = n;
            this.back = n;
        } else {
            this.back.next = n;
            this.back = n;
        }
        
        this.length++;
        
        return n;
    }
    pop() {
        if (this.length === 0) {
            return null;
        }
        
        const f = this.front;
        const v = f.value;
        this.length--;
        
        if (this.length === 0) {
            this.front = null;
            this.back = null;
        } else {
            this.front = this.front.next;
        }
        
        return v;
    }
}

function solution(queue1, queue2) {
    let answer = -1;
    
    let s1 = queue1.reduce((acc, cur) => acc + cur, 0);
    let s2 = queue2.reduce((acc, cur) => acc + cur, 0);
    
    const s = s1 + s2;
    
    if (s % 2 !== 0) {
        return answer;
    }
    
    let cnt = 0;
    const q1 = new Queue();
    const q2 = new Queue();
    
    queue1.forEach((x) => q1.push(x));
    queue2.forEach((x) => q2.push(x));
    
    const n = queue1.length + queue2.length;
    
    while (cnt < n*2 + 1) {
        if (s1 === s2) {
            return cnt;
        }
        cnt++;
        if (s1 > s2) {
            const f = q1.pop();
            q2.push(f);
            s1 -= f
            s2 += f
        } else {
            const f = q2.pop();
            q1.push(f);
            s1 += f
            s2 -= f
        }
    }
    
    return -1;
}