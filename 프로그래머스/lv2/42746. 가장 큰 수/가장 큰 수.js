function sort(a,b) {
    const le = Number(`${a}${b}`),
          ri = Number(`${b}${a}`);
    return ri - le;
}

function solution(numbers) {
    const answer = numbers.sort(sort);
    let zero = -1;
    for (let i=0; i<answer.length; i++) {
        if (answer[i] !== 0)  {
            break;
        }
        zero = i;
    }
    if (zero === answer.length - 1) {
        return "0";
    }
    if (zero !== -1) {
        return answer.slice(i+1).join("");
    }
    return answer.join("");
}