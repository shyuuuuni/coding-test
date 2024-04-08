const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let line = 0;

// 행, 열, 화산 개수
const [m, n, v] = input[line++].split(' ').map(Number);

// 시작 지점
const [x, y] = input[line++].split(' ').map(Number); 

const board = Array.from(Array(m), () => {
  return input[line++].split(' ').map(Number);
});

const volcano = Array.from(Array(v), () => {
  return input[line++].split(' ').map(Number);
});

// pq
class PriorityQueue {
  constructor() {
    this.queue = [];
  }
  push(x) {
    this.queue.push(x);
    this.upHeap();
  }
  upHeap() {
    let ptr = this.queue.length - 1;
    while (ptr > 0) {
      const parent = Math.floor((ptr - 1) / 2);
      if (this.queue[ptr].time < this.queue[parent].time) {
        this.swap(ptr, parent);
        ptr = parent;
        continue;
      }
      break;
    }
  }
  swap(i, j) {
    [this.queue[i], this.queue[j]] = [this.queue[j], this.queue[i]];
  }
  pop() {
    if (this.queue.length === 0) {
      throw 'empty queue';
    }
    this.swap(0, this.queue.length - 1);
    const result = this.queue.pop();
    this.downHeap();

    return result;
  }
  downHeap() {
    let ptr = 0;
    while (ptr < this.queue.length) {
      let left = ptr * 2 + 1, right = ptr * 2 + 2;
      let gts = ptr;
      if (left < this.queue.length && this.queue[gts].time > this.queue[left].time) {
        gts = left;
      }
      if (right < this.queue.length && this.queue[gts].time > this.queue[right].time) {
        gts = right;
      }
      if (ptr === gts) {
        break;
      }
      this.swap(ptr, gts);
      ptr = gts;
    }
  }
  top() {
    return this.queue[0];
  }
  size() {
    return this.queue.length;
  }
}

const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function solution() {
  const X = x - 1, Y = y - 1; // 0-based
  const visited = Array.from(Array(m), () => {
    return Array.from(Array(n)).fill(-1);
  });

  let time = 0;
  let answer = { maxTime: 0, maxHeight: board[X][Y] };

  const moves = [];
  const volcanos = [];
  const volcanoQueue = new PriorityQueue();

  moves.push({ x: X, y: Y, time: 0 });
  visited[X][Y] = 0;
  volcano.forEach((vol) => {
    visited[vol[0] - 1][vol[1] - 1] = 100; // 화산은 지날 수 없음
    volcanoQueue.push({ x: vol[0] - 1, y: vol[1] - 1, time: vol[2] });
  })
  
  while (time <= 5000) {
    // const b = [];
    // for (let i = 0; i < m; i++) {
    //   const a = [];
    //   for (let j = 0; j < n; j++) {
    //     if (visited[i][j] === -1) {
    //       a.push('O');
    //     } else if (visited[i][j] !== Infinity && 0 <= visited[i][j]) {
    //       a.push('X');
    //     } else {
    //       a.push('I');
    //     }

    //   }
    //   b.push(a.join(''));
    // }
    // console.log(answer, time, b.join('\n'));

    while (volcanoQueue.size() > 0 && volcanoQueue.top().time <= time) {
      const V = volcanoQueue.pop();
      if (visited[V.x][V.y] === Infinity) {
        continue;
      }
      volcanos.push(V);
      visited[V.x][V.y] = Infinity;
    }
    while (volcanos.length > 0 && volcanos[0].time <= time) {
      const { x, y, time: _time } = volcanos.shift();
      for (let i = 0; i < 4; i++) {
        const nx = x + dx[i];
        const ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (visited[nx][ny] === Infinity) continue;
        visited[nx][ny] = Infinity;
        volcanos.push({ x: nx, y: ny, time: _time+1 });
      }
    }
    

    while (moves.length > 0 && moves[0].time <= time) {
      const { x, y, time: _time } = moves.shift();

      for (let i = 0; i < 4; i++) { 
        const nx = x + dx[i];
        const ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (visited[nx][ny] !== -1) continue;

        if (board[nx][ny] > answer.maxHeight || (board[nx][ny] === answer.maxHeight && answer.time < _time+1)) {
          answer.maxHeight = board[nx][ny];
          answer.maxTime =  _time+1
        }
        visited[nx][ny] = _time + 1;
        moves.push({ x: nx, y: ny, time: _time+1 });
      }
    }

    if (moves.length === 0) {
      return [answer.maxHeight, answer.maxTime];
    }
    time++;
  }

  return [answer.maxHeight, answer.maxTime]
}

const answer = solution();
console.log(answer.join(' '));