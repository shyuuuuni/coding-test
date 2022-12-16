"use strict";

const getLowerBound = (arr, target) => {
  let le = 0,
    ri = arr.length;
  while (le < ri) {
    const mid = Math.floor((le + ri) / 2);
    if (target <= arr[mid]) {
      ri = mid;
    } else {
      le = mid + 1;
    }
  }
  return ri;
};

const [n, x] = require("fs").readFileSync("/dev/stdin").toString().split("\n");
const N = Number(n);
const inputs = x.split(" ").map(Number);
const s = new Set(inputs);
const arr = Array.from(s).sort((a, b) => a - b);

console.log(inputs.map((x) => getLowerBound(arr, x)).join(" "));
