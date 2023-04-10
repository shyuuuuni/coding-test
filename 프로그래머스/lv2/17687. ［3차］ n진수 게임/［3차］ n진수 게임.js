/*
2진수 기준
0 = 0 -> 0
1 = 1 -> 1
2 = 10 -> 10이상이므로 1/0 말하기
3 = 11 -> 10이상이므로 1/1 말하기
4 = 100 -> 10이상이므로 100 말하기

m = 인원수, t = 내가 말할 숫자 수
필요한 전체 길이 = m * t (m명이 t개씩)
*/

function solution(n, t, m, p) {
    let i = 0,
        s = "";
    
    while (s.length < m*t) {
        s = s.concat(i.toString(n));
        i++;
    }
    
    const answer = [...s].filter((c,i) => {
        return i % m + 1 === p;
    }).map((c) => c.toUpperCase()).slice(0, t);
    
    return answer.join("");
}