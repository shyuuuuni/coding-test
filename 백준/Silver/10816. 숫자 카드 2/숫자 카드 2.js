"use strict";

// target 보다 큰 가장 왼쪽 원소 찾기
const upperBound = (arr, target) => {
  let le = 0,
    ri = arr.length;
  while (le < ri) {
    const mid = Math.floor((le + ri) / 2);
    if (target < arr[mid]) {
      ri = mid;
    } else {
      le = mid + 1;
    }
  }
  return ri;
};

// target 보다 작거나 같은 가장 왼쪽 인덱스 찾기
const lowerBound = (arr, target) => {
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

const [n, c, m, q] = require("fs").readFileSync("/dev/stdin").toString().split("\n");
const N = Number(n);
const cards = c
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);
const M = Number(m);
const quizs = q.split(" ").map(Number);

console.log(quizs.map((i) => upperBound(cards, i) - lowerBound(cards, i)).join(" "));
