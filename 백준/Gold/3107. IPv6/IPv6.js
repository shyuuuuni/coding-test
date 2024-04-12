const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const hasDoubleColon = input.includes('::');

const format = (token) => {
  const needs = 4 - token.length;

  return '0'.repeat(needs) + token;
}

// token - :와 숫자로만 이루어짐
const parse = (token) => {
  const result = token.split(':').map(format);

  return result;
}


let answer;

if (hasDoubleColon) {
  const [left, right] = input.split('::');

  if (left === '') {
    const parsedRight = parse(right);
    const needs = 8 - parsedRight.length;

    answer = [...Array.from({ length: needs }, () => '0000'), ...parsedRight];
  } else if (right === '') {
    const parsedLeft = parse(left);
    const needs = 8 - parsedLeft.length;

    answer = [...parsedLeft, ...Array.from({ length: needs }, () => '0000')];
  } else {
    const parsedLeft = parse(left);
    const parsedRight = parse(right);
    const needs = 8 - parsedLeft.length - parsedRight.length;

    answer = [...parsedLeft, ...Array.from({ length: needs }, () => '0000'), ...parsedRight];
  }
} else {
  answer = parse(input);
}

console.log(answer.join(':'));