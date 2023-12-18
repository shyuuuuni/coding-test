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
        } else {
            this.last.next = node;
            this.last = node;
        }
        
        this.size++;
        
        return node.value;
    }
    shift() {
        if (this.size === 0) {
            throw '큐가 비었습니다.';
        }
        
        const node = this.first;
        this.size--;
        
        if (this.size === 0) {
            this.first = null;
            this.last = null;
        } else {
            this.first = this.first.next;
        }
        
        return node.value;
    }
}

function solution(n, roads, sources, destination) {
    const adj = Array.from({ length: n+1 }, () => []);
    const dist = Array.from({ length: n+1 }, () => Infinity);
    
    roads.forEach(([a, b]) => {
        adj[a].push(b);
        adj[b].push(a);
    });
        
    const queue = new Queue();
    queue.push(destination);
    dist[destination] = 0;
    
    while (queue.size > 0) {
        const cur = queue.shift();
        const nexts = adj[cur];
        
        nexts.forEach((next) => {
            if (dist[next] < dist[cur] + 1) {
                return;
            }
            queue.push(next);
            dist[next] = dist[cur] + 1;
        })
    }
    
    return sources.map((source) => dist[source] === Infinity ? -1 : dist[source]);
}