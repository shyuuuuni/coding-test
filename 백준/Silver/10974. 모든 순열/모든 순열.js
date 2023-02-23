/**
 * 입력한 배열을 다음 순열로 변경하고 반환합니다.
 * 만약 마지막 순열(내림차순 정렬)일 경우 false 를 반환합니다. 
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * ...
 * 4 3 2 1
 */
function nextPermutation(arr) {
  let i = arr.length - 2,
      j = arr.length - 1;

  // 오름차순이 유지되는 가장 큰 인덱스 i를 계산
  while (arr[i + 1] <= arr[i]) {
    i--;
  }
  // i+1 인덱스부터는 내림차순 정렬인 상태, i가 음수면 내림차순(종료)
  if (i < 0) {
    return false;
  }

  // 내림차순인 부분에서 arr[i] < arr[j] 를 만족하는 가장 큰 인덱스 j를 계산
  while (arr[j] <= arr[i]) {
    j--;
  }

  // console.log("i:", i, "j:", j);

  // arr[i]와 arr[j] 를 교환
  [arr[i], arr[j]] = [arr[j], arr[i]];

  // 내림차순이던 부분(i+1 인덱스부터) 을 reverse해서 다음 순열로 변경
  const next = arr.slice(i + 1).reverse();
  arr.splice(i + 1, next.length, ...next);

  return arr;
}

function main () {
  const fs = require("fs");
  const n = Number(fs.readFileSync("/dev/stdin").toString());
  const arr = Array.from({ length: n }, (_, i) => i + 1);
  do {
    console.log(arr.join(" "));
  } while (nextPermutation(arr));
}

main();