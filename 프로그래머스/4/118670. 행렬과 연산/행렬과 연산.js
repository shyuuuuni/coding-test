class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}
// [front] - a - b - [back]  <- next / prev -> 
class DoublyLinkedList {
    constructor() {
        this.size = 0;
        this.front = null;
        this.back = null;
    }
    pushFront(value) {
        const node = new Node(value);
        
        if (this.size === 0) {
            this.front = node;
            this.back = node;
        } else {
            node.prev = this.front;
            this.front.next = node;
            this.front = node;
        }
        
        this.size++;
        
        return node.value;
    }
    pushBack(value) {
        const node = new Node(value);
        
        if (this.size === 0) {
            this.front = node;
            this.back = node;
        } else {
            node.next = this.back;
            this.back.prev = node;
            this.back = node;
        }
        
        this.size++;
        
        return node.value;
    }
    popFront() {
        if (this.size === 0) {
            throw new Error('원소가 없습니다.');
        }
        const front = this.front;
        
        if (this.size === 1) {
            this.front = null;
            this.back = null;
        } else {
            this.front = this.front.prev;
            this.front.next = null;
        }
        
        this.size--;
        
        return front.value;
    }
    popBack() {
        if (this.size === 0) {
            throw new Error('원소가 없습니다.');
        }
        const back = this.back;
        
        if (this.size === 1) {
            this.front = null;
            this.back = null;
        } else {
            this.back = this.back.next;
            this.back.prev = null;
        }
        
        this.size--;
        
        return back.value;
    }
    print(flag = true) {
        let ptr = this.front;
        
        const s = [];
        
        while (ptr !== null) {
            s.push(ptr.value);
            ptr = ptr.prev;
        }
        
        if (flag) {
            console.log(`[${s.join(' ')}]`);
        }
        
        return s;
    }
}

function solution(rc, operations) {
    var answer = [[]];
    
    const r = rc.length,
          c = rc[0].length;
    
    const left = new DoublyLinkedList(),
          right = new DoublyLinkedList();
    
    const mids = new DoublyLinkedList();
    
    rc.forEach((row) => {
        const mid = new DoublyLinkedList();
        
        row.forEach((x, j) => {
            if (j === 0 || j === c-1) {
                return;
            }
            mid.pushBack(x);
        })
        
        mids.pushBack(mid);
    });
    
    for (let i=0; i<r; i++) {
        for (let j=0; j<c; j++) {
            if (j === 0) {
                left.pushBack(rc[i][j]);
            } else if (j === c-1) {
                right.pushBack(rc[i][j]);
            }
        }
    }
    
    function getAnswer() {
        const _answer = [];
        
        const tmp = mids.print(false);
        const _mids = tmp.map((mid) => mid.print(false)),
              _left = left.print(false),
              _right = right.print(false);
        
        for (let i=0; i<r; i++) {
            _answer.push([_left[i], ..._mids[i], _right[i]]);
        }
        
        return _answer;
    }
    
    function shiftRow() {
        const bottom = mids.popBack();
        mids.pushFront(bottom);
        
        const lBottom = left.popBack();
        left.pushFront(lBottom);
        
        const rBottom = right.popBack();
        right.pushFront(rBottom);
    }
    
    function rotate() {
        const lTop = left.popFront();
        mids.front.value.pushFront(lTop);
        
        const tBack = mids.front.value.popBack();
        right.pushFront(tBack);
        
        const rBack = right.popBack();
        mids.back.value.pushBack(rBack);
        
        const bTop = mids.back.value.popFront();
        left.pushBack(bTop);
    }
    
    operations.forEach((op) => {
        if (op === 'ShiftRow') {
            shiftRow();
        } else if (op === 'Rotate') {
            rotate();
        }
    })
    
    answer = getAnswer();
    
    return answer;
}