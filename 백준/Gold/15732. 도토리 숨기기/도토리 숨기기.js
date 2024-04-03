const fs = require('fs');
const input = fs.readFileSync(0, "utf-8").trim().toString().split('\n');

const [x, ...y] = input;
const [n, k, d] = x.split(' ').map(Number);
const rules = y.map((s) => s.split(' ').map(Number));

let left = 1,
  right = n;

while (left < right) {
  const mid = Math.floor((left + right) / 2);
  let cur = 0;

  for (let i = 0; i < k; i++) {
    const [a, b, c] = rules[i];

    if (mid < a) {
      continue;
    }
    if (b <= mid) {
      cur += Math.floor((b - a) / c) + 1;
      continue;
    }
    cur += Math.floor((mid - a) / c) + 1;
  }

  if (d <= cur){
    right = mid;
  } else {
    left = mid + 1;
  }
}
  
console.log(right);