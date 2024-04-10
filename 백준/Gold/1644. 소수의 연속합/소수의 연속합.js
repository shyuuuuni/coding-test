const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const n = Number(input);

const isPrime = Array.from(Array(n+1), () => true);

const primes = [];

isPrime[0] = false;
isPrime[1] = false;

for (let i = 2; i <= n; i++) {
  if (!isPrime[i]) {
    continue;
  }
  primes.push(i);
  for (let j = 2; i*j <= n+1; j++) {
    isPrime[i * j] = false;
  }
}

let answer = 0;
let sum = 0, left = 0, right = 0;

while (right < primes.length) {
  sum += primes[right];
  // 누적합 초과
  while (n < sum && left < primes.length) {
    sum = sum - primes[left++];
  }
  if (sum === n) {
    answer++;
  }
  right++;
}

console.log(answer);