const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let line = 0;
let tc = Number(input[line++]);

for (let i = 1; i <= tc; i++) {
  const n = Number(input[line++]);
  const rooks = [];
  for (let j = 0; j < n; j++) {
    rooks.push(input[line++].split(' ').map(Number));
  }
  const result = solution(n, rooks);
  console.log(`Case #${i}: ${result}`);
}

function solution(n, rooks) {
  let answer = 0;

  rooks.sort((a, b) => {
    return a[0] - b[0]; // row 기준 오름차순 정렬
  });

  for (let i = 1; i <= n; i++) {
    answer += Math.abs(rooks[i - 1][0] - i);
  }

  rooks.sort((a, b) => {
    return a[1] - b[1]; // col 기준 오름차순 정렬
  })

  for (let i = 1; i <= n; i++) {
    answer += Math.abs(rooks[i - 1][1] - i);
  }

  return answer;
}