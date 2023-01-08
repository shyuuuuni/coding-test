class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class AdditionalQueue {
    constructor() {
        this.first = null;
        this.last = null;
        this.size = 0;
        this.sum = 0;
    }
    push (value) {
        const node = new Node(value);
        if (this.size === 0) {
            this.first = node;
            this.last = node;
            this.size++;
            this.sum += value;
            return value;
        }
        this.last.next = node;
        this.last = node;
        this.size++;
        this.sum += value;
    }
    pop() {
        if (this.size === 0) {
            return undefined;
        }
        const value = this.first.value;
        if (this.first === this.last) {
            this.first = null;
            this.last = null;
            this.size--;
            this.sum -= value;
            return value;
        }
        this.first = this.first.next;
        this.size--;
        this.sum -= value;
        return value;
    }
}

function solution(queue1, queue2) {
    let answer = 0;
    
    const MAX_REC = (queue1.length + queue2.length) * 2;
    
    const q1 = new AdditionalQueue();
    const q2 = new AdditionalQueue();
    
    queue1.forEach((e1) => q1.push(e1));
    queue2.forEach((e2) => q2.push(e2));
    
    while (q1.sum !== q2.sum && answer < MAX_REC) {
        let from, to;
        if (q1.sum < q2.sum) {
            from = q2;
            to = q1;
        } else {
            from = q1;
            to = q2;
        }
        const elem = from.pop();
        to.push(elem);
        answer++;
    }
    
    if (answer === MAX_REC) {
        return -1;
    }
    return answer;
}