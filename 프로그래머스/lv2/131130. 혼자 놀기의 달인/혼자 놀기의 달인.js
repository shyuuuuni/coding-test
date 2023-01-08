class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Queue {
    constructor() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }
    push(value) {
        const node = new Node(value);
        if (this.size === 0) {
            this.first = node;
            this.last = node;
            this.size++;
            return value;
        }
        this.last.next = node;
        this.last = node;
        this.size++;
        return value;
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
            return value;
        }
        this.first = this.first.next;
        this.size--;
        return value;
    }
    top() {
        if (this.size === 0) {
            return undefined;
        }
        return this.first.value;
    }
}

function solution(cards) {
    const N = cards.length;
    const indexes = Array.from({length : N}, (v,i) => i+1);
    const checked = Array(N).fill(false);
    const cardsCount = [0];
    
    let checkedCount = 0;
    
    while (checkedCount < N) {
        // find starting point;
        let ptr = indexes.find((v,i) => !checked[i]) - 1;
        let cur = 0;
        
        // calc count
        while (!checked[ptr]) {
            checkedCount++;
            checked[ptr] = true;
            cur++;
            ptr = cards[ptr] - 1;
        }
        
        cardsCount.push(cur);
    }
    
    
    cardsCount.sort((a,b) => b-a);
    
    return cardsCount[0] * cardsCount[1];
}