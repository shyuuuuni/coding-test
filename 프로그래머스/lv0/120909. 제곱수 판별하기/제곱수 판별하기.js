function solution(n) {
    const sq = Math.sqrt(n);
    return sq === Math.floor(sq) ? 1 : 2;
}