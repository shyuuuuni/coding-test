function solution(data, col, row_begin, row_end) {
    const 정렬된_데이터 = data.sort((a, b) => {
        if (a[col-1] !== b[col-1]) {
            return a[col-1] - b[col-1];
        }
        return b[0] - a[0];
    })
    const answer = 정렬된_데이터.reduce((acc, cur, i) => {
        if (row_begin-1 <= i && i <= row_end-1) {
            return acc ^ cur.reduce((acc, cur) => acc + cur % (i+1), 0);
        }
        return acc;
    }, 0);
    
    return answer;
}