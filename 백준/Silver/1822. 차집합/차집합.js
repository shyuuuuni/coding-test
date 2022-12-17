"use strcit";

const binarySearch = (arr, target) => {
  let le = 0,
    ri = arr.length;
  while (le < ri) {
    const mid = Math.floor((le + ri) / 2);
    if (target === arr[mid]) {
      return mid;
    } else if (target < arr[mid]) {
      ri = mid;
    } else {
      le = mid + 1;
    }
  }
  return -1;
};

const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
const arrA = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);
const arrB = input[2]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);
const answer = arrA.filter((target) => binarySearch(arrB, target) === -1);

console.log(answer.length);
if (answer.length) {
  console.log(answer.join(" "));
}
