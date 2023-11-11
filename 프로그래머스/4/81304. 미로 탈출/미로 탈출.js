class Node {
  constructor(val, priority) {
    this.val = val;
    this.priority = priority;
  }
}
class MaxPriorityQueue {
  constructor() {
    this.arr = [];
  }

  enqueue(val, priority) {
    const newNode = new Node(val, priority);
    this.arr = [...this.arr, newNode];
    this.bubbleUp();
  }

  bubbleUp() {
    let index = this.arr.length - 1;
    const elem = this.arr[index];

    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      let parent = this.arr[parentIndex];

      if (elem.priority <= parent.priority) break;

      this.arr[parentIndex] = elem;
      this.arr[index] = parent;
      index = parentIndex;
    }
  }

  dequeue() {
    const max = this.arr[0];
    const end = this.arr.pop();

    if (this.arr.length > 0) {
      this.arr[0] = end;
      this.sinkDown();
    }

    return max;
  }

  sinkDown() {
    let index = 0;
    const { length } = this.arr;
    const elem = this.arr[index];

    while (true) {
      let leftChildIndex = 2 * index + 1;
      let rightChildIndex = 2 * index + 2;
      let leftChild = null;
      let rightChild = null;
      let swap = null;

      if (leftChildIndex < length) {
        leftChild = this.arr[leftChildIndex];
        if (leftChild.priority > elem.priority) {
          swap = leftChildIndex;
        }
      }

      if (rightChildIndex < length) {
        rightChild = this.arr[rightChildIndex];
        if (
          (swap === null && rightChild.priority > elem.priority) ||
          (swap !== null && rightChild.priority > leftChild.priority)
        ) {
          swap = rightChildIndex;
        }
      }

      if (swap === null) break;

      this.arr[index] = this.arr[swap];
      this.arr[swap] = elem;
      index = swap;
    }
  }
}

function solution(n, start, end, roads, traps) {
    // dist[x][y]: 스위치 상태(비트마스크) x일 때 start부터 y까지의 거리
    const dist = Array.from({ length: (1 << traps.length)+1 }, () => {
        return Array.from({ length: n+1 }, () => {
            return Infinity;
        });
    });
    // adj[x][y]: x -> y로 가는 간선 정보
    const adj = Array.from({ length: n+1 }, () => {
        return Array.from({ length: n+1 }, () => {
            return Infinity;
        });
    });
    // trapIndex[x]: -1 if non-trap, index of trap if x is trap
    const trapIndex = Array.from({ length: n+1 }, () => {
        return -1;
    });
    
    roads.forEach(([start, end, value]) => {
        adj[start][end] = Math.min(adj[start][end], value);
    });
    for (let i=0; i<=n; i++) {
        adj[i][i] = 0;
    }
    
    traps.forEach((t, i) => {
        trapIndex[t] = i;
    });
    
    const queue = new MaxPriorityQueue();
    
    // [index, trapStatus(bits), distance]
    queue.enqueue({
        index: start,
        bits: 0,
        distance: 0,
    }, 0);
    dist[0][start] = 0;
    
    while (queue.arr.length > 0) {
        const { index, bits, distance } = queue.dequeue().val;
        
        console.log(index, bits, distance);
        
        if (index === end) {
            return distance;
        }
        
        const cIsTrap = trapIndex[index] !== -1;
        const cIsTrapOff = (bits & (1 << trapIndex[index])) === 0;
        
        for (let next=1; next<=n; next++) {
            if (next === index) {
                continue;
            }
            if (adj[index][next] === Infinity && adj[next][index] === Infinity) {
                continue;
            }
            
            const nIsTrap = trapIndex[next] !== -1;
            const nIsTrapOff = (bits & (1 << trapIndex[next])) === 0;
            
            let nextBits = bits;
            if (nIsTrap) {
                nextBits = bits ^ (1 << trapIndex[next]);
            }
            
            if ((!cIsTrap && !nIsTrap) || (cIsTrapOff && nIsTrapOff) || (!cIsTrapOff && !nIsTrapOff)) {
                const nDist = adj[index][next];
                if (distance + nDist < dist[nextBits][next]) {
                    dist[nextBits][next] = distance + nDist;
                    queue.enqueue({ index: next, bits: nextBits, distance: distance + nDist }, -(distance + nDist));
                }
            } else {
                const nDist = adj[next][index];
                if (distance + nDist < dist[nextBits][next]) {
                    dist[nextBits][next] = distance + nDist;
                    queue.enqueue({ index: next, bits: nextBits, distance: distance + nDist }, -(distance + nDist));
                }
            }
        }
    }
    
    return -1;
}