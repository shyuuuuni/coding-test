class Node {
    constructor(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class DLinkedList {
    constructor() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }
    pushLast(value) {
        const node = new Node(value);
        
        if (this.size === 0) {
            this.first = node;
            this.last = node;
        } else {
            this.last.next = node;
            node.prev = this.last;
            this.last = node;
        }
        
        this.size++;
        return node;
    }
    remove(node) {
        this.size--;
        if (node === this.first) {
            this.first = node.next;
            this.first.prev = null;
            return this.first;
        }
        if (node === this.last) {
            this.last = node.prev;
            this.last.next = null;
            return this.last;
        }
        const p = node.prev,
              n = node.next;
        p.next = n;
        n.prev = p;
        return n;
    }
    insert(node) {
        this.size++;
        const p = node.prev,
              n = node.next;
        
        if (n === this.first) {
            this.first = node;
            n.prev = node;
            return;
        }
        if (p === this.last) {
            this.last = node;
            p.next = node;
            return;
        }
        n.prev = node;
        p.next = node;
    }
}

class Table {
    constructor(tableSize, startPtr) {
        this.linkedList = new DLinkedList();
        this.ptr = null;
        this.init(tableSize, startPtr);
        this.callStack = [];
    }
    init(n, k) {
        for (let i=0; i<n; i++) {
            const node = this.linkedList.pushLast(i);
            if (i === k) {
                this.ptr = node;
            }
        }
    }
    up(n) {
        // O(n)
        for (let i=0; i<n; i++) {
            this.ptr = this.ptr.prev;
        }
    }
    down(n) {
        // O(n)
        for (let i=0; i<n; i++) {
            this.ptr = this.ptr.next;
        }
    }
    removeCurrent() {
        this.callStack.push(this.ptr);
        this.ptr = this.linkedList.remove(this.ptr);
    }
    rollback() {
        const node = this.callStack.pop();
        this.linkedList.insert(node);
    }
}

function solution(n, k, cmd) {
    const answer = Array.from(Array(n), () => "X");
    const table = new Table(n, k);
    
    cmd.forEach((command) => {
        if (command.startsWith("D")) {
            const count = command.split(" ")[1];
            table.down(count);
            return;
        }
        if (command.startsWith("U")) {
            const count = command.split(" ")[1];
            table.up(count);
            return;
        }
        if (command === "C") {
            table.removeCurrent();
        }
        if (command === "Z") {
            table.rollback();
        }
    });
    
    let iter = table.linkedList.first;
    do {
        const i = iter.value;
        answer[i] = "O";
        iter = iter.next;
    } while (iter);
    
    return answer.join("");
}