function solution(routes) {
    let answer = 1; // 1개는 필수
    let prev = Infinity;
    
    routes.sort((a,b) => {
        if (a[0] === b[0]) {
            return a[1] - b[1];
        }
        return a[0] - b[0];
    });
    
    routes.forEach(([stt,end], i) => {
        if (prev < stt) {
            answer++;
            prev = end
        } else {
            prev = Math.min(prev, end);
        }
    });
    
    return answer;
}