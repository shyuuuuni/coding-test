const fs = require('fs');

const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

let line = 0;
let tc = Number(input[line++]);
  
while (0 < tc) {
  tc = tc - 1;
  const [n, k] = input[line++].split(' ').map(Number);
  const d = [null, ...input[line++].split(' ').map(Number)];
  const adj = Array.from({ length: n + 1 }, () => []); // adj[t] : t를 짓기 위해 건설이 필요한 목록
  const builtTime = Array.from({ length: n + 1 }, () => null);

  for (let i = 0; i < k; i++) {
    const [f, t] = input[line++].split(' ').map(Number);
    adj[t].push(f);
  }

  const w = Number(input[line++]);

  function getBuiltTime(index) {
    if (builtTime[index] !== null) {
      return builtTime[index];
    }

    builtTime[index] = d[index];

    if (adj[index].length === 0) {
      return d[index];
    }

    const maxBt = adj[index].reduce((maxBuiltTime, cur) => {
      return Math.max(maxBuiltTime, getBuiltTime(cur));
    }, -1);

    builtTime[index] += maxBt;

    return builtTime[index];
  }

  const answer = getBuiltTime(w);

  console.log(answer);
}