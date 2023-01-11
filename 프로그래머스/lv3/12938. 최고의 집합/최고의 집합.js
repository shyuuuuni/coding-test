function solution(n, s) {
    const token = Math.floor(s/n); // 원소 한개당 포함할 최소 수
    let rest = s - n * token;
    
    if (token === 0) {
        return [-1];
    }
    const arr = Array(n).fill(token);
    return arr.map((e) => {
        if (0 < rest) {
            rest--;
            return e + 1;
        }
        return e;
    }).sort((a,b) => a-b)
}
