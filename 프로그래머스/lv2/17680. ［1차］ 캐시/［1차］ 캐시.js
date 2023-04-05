class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}
class Deque {
    constructor() {
        this.first = new Node(null);
        this.last = new Node(null);
        this.size = 0;
        
        // init
        this.first.next = this.last;
        this.last.prev = this.first;
    }
    popFirst() {
        if (this.size === 0) {
            return undefined;
        }
        const node = this.first.next;
        this.size--;
        
        const p = node.prev,
              n = node.next;
        p.next = n;
        n.prev = p;
        
        return node;
    }
    pushLast(value) {
        const node = new Node(value);
        this.size++;
        
        const p = this.last.prev,
              n = this.last;
        node.prev = p;
        p.next = node;
        node.next = n;
        n.prev = node;
        
        return node;
    }
    removeNode(node) {
        const p = node.prev,
              n = node.next;
        this.size--;
        
        p.next = n;
        n.prev = p;
        
        return node;
    }
    printAll() {
        let iter = this.first.next;
        const val = [];
        while (iter !== this.last) {
            val.push(iter.value);
            iter = iter.next;
        }
        console.log(this.size, val);
    }
}
class LRU {
    constructor(size) {
        this.map = new Map();
        this.deque = new Deque();
        this.size = size;
        this.time = 0;
    }
    insert(city) {
        // hit
        if (this.map.has(city)) {
            this.time += 1;
            const node = this.map.get(city);
            this.map.delete(city);
            this.deque.removeNode(node);
            const newNode = this.deque.pushLast(city);
            this.map.set(city, newNode);
            return;
        }
        // miss
        this.time += 5;
        if (this.size === 0) {
            return;
        }
        if (this.size <= this.deque.size) {
            const { value } = this.deque.popFirst();
            this.map.delete(value);
        }
        
        const node = this.deque.pushLast(city);
        this.map.set(city, node);
    }
}

function solution(cacheSize, cities) {
    const lru = new LRU(cacheSize);
    
    cities.forEach((city) => {
        lru.insert(city.toUpperCase());
    });
    
    return lru.time;
}