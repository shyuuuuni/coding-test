const fs = require('fs');

let line = 0;
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let tc = Number(input[line++]);

while (tc--) {
  // 0 <= x,y <= 2^31
  let [le, ri] = input[line++].split(' ').map(Number);
  let answer = ri;

  ri = ri - le; // 3
  le = 0;       // 0

  const getMaxSeqOdd = (num) => num * num;
  const getMaxSeqEven = (num) => {
    // a0 = 0;
    // a1 = a0 + 2*1
    // a2 = a1 + 2*2
    // a3 = a2 + 2*3

    // an = 0 + 2*1 + 2*2 + 2*3 + ...2*n = 2(sig(n))
    return num * (num + 1);
  }

  let i = 1;

  while (i <= ri) {
    const odd = getMaxSeqOdd(i);
    const even = getMaxSeqEven(i);

    if (ri <= odd) {
      console.log(i * 2 - 1);
      break;
    }
    if (ri <= even) {
      console.log(i * 2);
      break;
    }

    i++;
  }
}

/**
 * d=1) 1 -        +1         +1v
 * d=2) 2 -       +1 +1       +2
 * d=3) 3 -     +1 +1 +1
 * d=4) 3 -     +1 +2 +1      +4v
 * d=5) 4 -    +1 +2 +1 +1
 * d=6) 4 -    +1 +2 +2 +1    +6
 * d=7) 5 -   +1 +2 +2 +1 +1
 * d=8) 5 -   +1 +2 +2 +2 +1
 * d=9) 5 -   +1 +2 +3 +2 +1  +9v
 * ...
 * d=n) 6 - +1 +2 +3 +3 +2 +1 +12
 * d=m) 7 - +1 +2 +3 +4 +3 +2 +1 +16v
 * 
 * -> 홀수일 땐 x^2형태
 * -> 짝수일 뗀? 2 6 12 20 30? -> +4 +6 +8 +10 -> 등차수열?
 */