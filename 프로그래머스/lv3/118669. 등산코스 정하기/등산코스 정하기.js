// class Heap {
//     constructor(compare) {
//         this.heap = [];
//         this.compare = compare;
//     }
//     swap(a, b) {
//         [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
//     }
//     size() {
//         return this.heap.length;
//     }
//     push(value) {
//         this.heap.push(value);
//         this.upHeap();
//     }
//     pop() {
//         if (this.size() <= 0) {
//             return undefined;
//         }
//         this.swap(0, this.size()-1);
//         const value = this.heap.pop();
//         this.downHeap(0);
//         return value;
//     }
//     upHeap() {
//         let current = this.size()-1;
//         while (0 < current) {
//             const parent = Math.floor((current - 1) / 2);
//             if (this.compare(this.heap[parent], this.heap[current])) {
//                 return;
//             }
//             this.swap(parent, current);
//             current = parent;
//         }
//     }
//     downHeap(i) {
//         let current = i;
//         while (current < this.size()) {
//             const left = current * 2;
//             const right = current * 2 + 1;
            
//             if (!this.heap[left]) {
//                 break;
//             }
//             if (!this.heap[right] && this.compare(this.heap[current], this.heap[left])) {
//                 break;
//             }
//             if (!this.heap[right]) {
//                 this.swap(current, left);
//                 continue;
//             }
            
//             const next = this.compare(this.heap[left], this.heap[right]) ? right : left;
//             if (this.compare(this.heap[current], this.heap[next])) {
//                 break;
//             }
//             this.swap(current, next);
//             current = next;
//         }
//     }
// }
class Heap {
    constructor(){
        this.items = [];
    }

    swap(idx1, idx2){
        [this.items[idx1], this.items[idx2]] = [this.items[idx2], this.items[idx1]];
    }

    findParentIdx(idx){
        return Math.floor((idx-1)/2);
    }

    findLeftChildIdx(idx){
        return idx*2+1;
    }

    findRightChildIdx(idx){
        return idx*2+2;
    }

    findParent(idx){
        return this.items[this.findParentIdx(idx)];
    }

    findLeftChild(idx){
        return this.items[this.findLeftChildIdx(idx)];
    }

    findRightChild(idx){
        return this.items[this.findRightChildIdx(idx)];
    }

    size(){
        return this.items.length;
    }
}

class MinHeap extends Heap{
    bubbleUp(){
        let index = this.items.length-1;

        while(this.findParent(index) && this.findParent(index)[1]>this.items[index][1]){
            this.swap(index, this.findParentIdx(index));
            index = this.findParentIdx(index);
        }
    }

    bubbleDown(){
        let index =0;

        while((this.findLeftChild(index) && this.findLeftChild(index)[1] < this.items[index][1]) || (this.findRightChild(index) && this.findRightChild(index)[1] < this.items[index][1])){
            let smallerIndex = this.findLeftChildIdx(index);

            if(this.findRightChild(index) &&
              this.findRightChild(index)[1] < this.items[smallerIndex][1]){
                smallerIndex = this.findRightChildIdx(index);
            }

            this.swap(index, smallerIndex);
            index = smallerIndex;
        }
    }

    add(value){
        this.items.push(value);
        this.bubbleUp();
    }

    poll(){
        if(this.size() === 1){
            return this.items.pop();
        }

        const value = this.items[0];
        this.items[0] = this.items.pop();
        this.bubbleDown();

        return value;
    }
}

function solution(n, paths, gates, summits) {
    const isGates = Array(n+1).fill(false);
    const isSummits = Array(n+1).fill(false);
    const intensity = Array(n+1).fill(Infinity);
    const graph = Array.from({length: n+1}, () => []);
    const pq = new MinHeap();
    
    paths.forEach(([ start, end, inst ]) => {
        graph[start].push([end, inst]);
        graph[end].push([start, inst]);
    });

    gates.forEach((gate) => {
        isGates[gate] = true;
        pq.add([gate, 0]);
        intensity[gate] = 0;
    });
    summits.forEach((summit) => {
        isSummits[summit] = true;
    });
    
    graph.map((path, start) => {
        if (isSummits[start]) {
            return [];
        }
        return path.filter(([end, inst]) => {
            return !isGates[end];
        });
    });
    
    while(0 < pq.size()) {
        const [idx, inst] = pq.poll();

        if (isSummits[idx] || intensity[idx] < inst) {
            continue;
        }

        graph[idx].forEach(([end, nextInst]) => {
            const totalInst = Math.max(inst, nextInst)
            if (totalInst < intensity[end]) {
                intensity[end] = totalInst;
                pq.add([end, totalInst]);
            }
        });
    }
    
    return summits.sort((a,b) => a-b).reduce((acc, summit) => {
        if (intensity[summit] < acc[1]) {
            return [summit, intensity[summit]];
        }
        return acc;
    }, [-1, Infinity]);
}