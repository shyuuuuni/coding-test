// node
class Node {
    constructor(value) {
        this.value = value;
        this.valid = true;
    }
    setInvalid() {
        this.valid = false;
    }
}

// max-heap
class MaxHeap {
  constructor() {
    this.heap = [];
    this.compare = (child, parent) => child.value <= parent.value;
  }

  swap(indexA, indexB) {
    [this.heap[indexA], this.heap[indexB]] = [this.heap[indexB], this.heap[indexA]];
  }

  size() {
    return this.heap.length;
  }

  push(value) {
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
    if (value.valid) {
        return value;
    }
    return this.pop();
  }

  upHeap() {
    let current = this.heap.length - 1;

    while (0 < current) {
      const parent = Math.floor((current - 1) / 2);
      if (this.compare(this.heap[current], this.heap[parent])) {
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
        if (this.compare(this.heap[leftChild], this.heap[current])) {
          break;
        }
        this.swap(current, leftChild);
        current = leftChild;
        continue;
      }
      // 오른쪽거가 더 작으면 true
      const nextChild = this.compare(this.heap[leftChild], this.heap[rightChild]) ? rightChild : leftChild;
      if (this.compare(this.heap[nextChild], this.heap[current])) {
        break;
      }
      this.swap(current, nextChild);
      current = nextChild;
    }
  }
}

// min-heap
class MinHeap {
  constructor() {
    this.heap = [];
    this.compare = (child, parent) => parent.value <= child.value;
  }

  swap(indexA, indexB) {
    [this.heap[indexA], this.heap[indexB]] = [this.heap[indexB], this.heap[indexA]];
  }

  size() {
    return this.heap.length;
  }

  push(value) {
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
    if (value.valid) {
        return value;
    }
    return this.pop();
  }

  upHeap() {
    let current = this.heap.length - 1;

    while (0 < current) {
      const parent = Math.floor((current - 1) / 2);
      if (this.compare(this.heap[current], this.heap[parent])) {
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
        if (this.compare(this.heap[leftChild], this.heap[current])) {
          break;
        }
        this.swap(current, leftChild);
        current = leftChild;
        continue;
      }
      // 오른쪽거가 더 작으면 true
      const nextChild = this.compare(this.heap[leftChild], this.heap[rightChild]) ? rightChild : leftChild;
      if (this.compare(this.heap[nextChild], this.heap[current])) {
        break;
      }
      this.swap(current, nextChild);
      current = nextChild;
    }
  }
}

function solution(operations) {
    const maxHeap = new MaxHeap();
    const minHeap = new MinHeap();
    
    operations.forEach((cur) => {
        const [ops, value] = cur.split(" ");
        if (ops === "I") {
            console.log("insert");
            const node = new Node(Number(value));
            maxHeap.push(node);
            minHeap.push(node);
        }
        if (ops === "D" && value === "1") {
            const node = maxHeap.pop();
            console.log("remove max", node);
            node?.setInvalid();
        }
        if (ops === "D" && value === "-1") {
            const node = minHeap.pop();
            console.log("remove min", node);
            node?.setInvalid();
        }
    });
    
    const maximum = maxHeap.pop()?.value ?? 0;
    const minimum = minHeap.pop()?.value ?? 0;
    
    return [maximum, minimum];
}