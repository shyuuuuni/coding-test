class Stack {
    constructor() {
        this.stack = [];
    }
    push(value) {
        this.stack.push(value);
    }
    pop() {
        if (this.stack.length === 0) {
            return null;
        }
        return this.stack.pop();
    }
    top() {
        if (this.stack.length === 0) {
            return null;
        }
        return this.stack[this.stack.length-1];
    }
}

function solution(order) {
    let answer = 0,
        p = 0;
    const stack = new Stack();
    
    for (let box=1; box<=order.length; box++) {
        stack.push(box);
        while (stack.top() === order[p]) {
            stack.pop();
            p++;
            answer++;
        }
    }
    
    return answer;
}