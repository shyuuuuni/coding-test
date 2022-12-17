class MaxHeap {
  constructor() {
    this.heap = [];
  }

  swap(indexA, indexB) {
    [this.heap[indexA], this.heap[indexB]] = [this.heap[indexB], this.heap[indexA]];
  }

  size() {
    return this.heap.length;
  }

  push(value) {
    // 1. 가장 뒤에 원소 추가
    this.heap.push(value);
    this.upHeap();
    return this.heap.length;
  }

  pop() {
    if (this.heap.length === 0) {
      return undefined;
    }
    this.swap(0, this.heap.length - 1);
    const value = this.heap.pop();
    this.downHeap(0);
    return value;
  }

  upHeap() {
    let current = this.heap.length - 1;

    while (0 < current) {
      const parent = Math.floor((current - 1) / 2);
      if (this.heap[current] <= this.heap[parent]) {
        return;
      }
      this.swap(parent, current);
      current = parent;
    }
  }

  downHeap(idx) {
    let current = idx;

    while (current < this.heap.length) {
      // CBT 구조 특징 : 특정 idx의 자식 노드 -> idx*2+1, idx*2+2
      let leftChild = current * 2 + 1;
      let rightChild = current * 2 + 2;

      if (this.heap[leftChild] === undefined) {
        break;
      }
      if (this.heap[rightChild] === undefined) {
        if (this.heap[leftChild] <= this.heap[current]) {
          break;
        }
        this.swap(current, leftChild);
        current = leftChild;
        continue;
      }
      const nextChild = this.heap[leftChild] < this.heap[rightChild] ? rightChild : leftChild;
      if (this.heap[nextChild] <= this.heap[current]) {
        break;
      }
      this.swap(current, nextChild);
      current = nextChild;
    }
  }
}

const [N, ...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
const pq = new MaxHeap();
console.log(
  arr
    .reduce((acc, cur) => {
      if (cur === 0) {
        acc.push(pq.pop() ?? 0);
        return acc;
      }
      pq.push(cur);
      return acc;
    }, [])
    .join("\n")
);
