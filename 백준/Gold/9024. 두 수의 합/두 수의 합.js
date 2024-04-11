const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let line = 0;

let n = Number(input[line++]);

for (let i = 0; i < n; i++) {
  const [_, k] = input[line++].split(' ').map(Number);
  const items = input[line++].split(' ').map(Number).sort((a, b) => a - b);
  
  let left = 0, right = items.length - 1;
  let answer = 0;
  let minimum = Math.abs(k - (items[0] + items[items.length - 1]));

  while (left < right) {
    const sum = items[left] + items[right];
    const cur = Math.abs(k - sum);

    if (cur < minimum) {
      minimum = cur;
      answer = 1;
    } else if (cur === minimum) {
      answer++;
    }

    if (sum <= k) {
      left++;
    } else {
      right--;
    }
  }

  console.log(answer);
}