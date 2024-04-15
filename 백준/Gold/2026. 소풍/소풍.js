const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let line = 0;

const [k, n, f] = input[line++].split(' ').map(Number);
const adj = Array.from(Array(n + 1), (_, i) => Array.from(Array(n + 1), (_, j) => i === j));
const inbounds = Array.from(Array(n + 1), () => 1);

for (let i = 0; i < f; i++) {
  const [a, b] = input[line++].split(' ').map(Number);
  adj[a][b] = adj[b][a] = true;
  inbounds[a]++;
  inbounds[b]++;
}

const trace = [];
let answer = -1;

const dfs = (index) => {
  if (answer !== -1) {
    return answer;
  }
  
  const count = trace.length;

  if (count === k) {
    answer = [...trace];
    return answer;
  }

  for (let i = index + 1; i <= n; i++) {
    if (inbounds[i] < k) {
      continue;
    }
    let flag = true;
    for (let j = 0; j < trace.length && flag; j++) {
      const to = trace[j];
      if (!adj[i][to]) {
        flag = false;
      }
    }
    if (!flag) {
      continue;
    }
    trace.push(i);
    dfs(i);
    trace.pop();
  }
}

for (let i = 1; i <= n; i++) {
  if (inbounds[i] < k) {
    continue;
  }
  if (answer !== -1) {
    break;
  }
  trace.push(i);
  dfs(i);
  trace.pop();
}

if (answer === -1) {
  console.log(answer);
} else {
  console.log(answer.slice(0, k).join('\n'));
}