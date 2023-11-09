class DNode {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}
class DLinkedList {
    constructor() {
        this.size = 0;
        this.head = null;
        this.tail = null;
    }
    pushBack(value) {
        const node = new DNode(value);
        
        if (this.size === 0) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.prev = node;
            node.next = this.tail;
            this.tail = node;
        }
        
        this.size++;
        
        return node;
    }
    iterate() {
        let ptr = this.head;
        const log = [];
        
        while (ptr !== null) {
            log.push(ptr.value);
            ptr = ptr.prev;
        }
        
        console.log(log.join(' '));
    }
}
class Table extends DLinkedList {
    constructor() {
        super();
        this.ptr = null;
        this.trashbox = [];
    }
    initPtr(n) {
        this.ptr = this.head;
        while (n--) {
            this.ptr = this.ptr.prev;
        }
    }
    moveUp(x) {
        while (x--) {
            if (this.ptr.next === null) {
                break;
            }
            this.ptr = this.ptr.next;
        }
    }
    moveDown(x) {
        while (x--) {
            if (this.ptr.prev === null) {
                break;
            }
            this.ptr = this.ptr.prev;
        }
    }
    cancel() {
        if (this.size === 0) {
            return null;
        }
        
        this.trashbox.push(this.ptr);
        
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
            this.ptr = null;
        } else if (this.ptr === this.tail) {
            this.tail = this.tail.next;
            this.tail.prev = null;
            this.ptr = this.tail;
        } else if (this.ptr === this.head) {
            this.head = this.head.prev;
            this.head.next = null;
            this.ptr = this.head;
        } else {
            const next = this.ptr.next;
            const prev = this.ptr.prev;
            
            next.prev = prev;
            prev.next = next;
            
            this.ptr = prev;
        }
        
        this.size--;
    }
    rollback() {
        if (this.trashbox.length === 0) {
            return null;
        }
        
        const lastnode = this.trashbox.pop();
        
        if (lastnode.next === null && lastnode.prev === null) {
            this.head = lastnode;
            this.tail = lastnode;
            this.ptr = lastnode;
        } else if (lastnode.next === null) {
            this.head.next = lastnode;
            this.head = lastnode;
        } else if (lastnode.prev === null) {
            this.tail.prev = lastnode;
            this.tail = lastnode;
        } else {
            const next = lastnode.next;
            const prev = lastnode.prev;
            
            next.prev = lastnode;
            prev.next = lastnode;
        }
        
        this.size++;
    }
}

function solution(n, k, cmd) {
    const table = new Table();
    
    for (let i=0; i<n; i++) {
        table.pushBack(i);
    }
    table.initPtr(k);
    
    cmd.forEach((c,i) => {
        const cs = c.split(' ');
        
        if (cs[0] === 'U') {
            const n = Number(cs[1]);
            table.moveUp(n);
        } else if (cs[0] === 'D') {
            const n = Number(cs[1]);
            table.moveDown(n);
        } else if (cs[0] === 'C') {
            table.cancel();
        } else if (cs[0] === 'Z') {
            table.rollback();
        }
    });
    
    const answer = Array(n).fill('X');
    let ptr = table.head;
    while (ptr !== null) {
        const x = ptr.value;
        answer[x] = 'O';
        ptr = ptr.prev;
    }
    
    return answer.join('');
}