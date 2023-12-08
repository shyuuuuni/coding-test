// [2, 3, -6, 1, 3, -1, 2, 4]
//+[2, -3, -6, -1, 3, 1, 2, -4]
//-[-2, 3, 6, 1, -3, -1, -2, 4] 

function solution(sequence) {
    let answer = -Infinity;
    
    const N = sequence.length;
    
    // pulsed[i][0/1]: +로 시작했을 때 배열 / -로 시작했을 때 배열
    const pulsed = Array.from({ length: N }, () => {
        return Array.from({ length: 2 }, () => [0, 0]);
    });
    // acc[i][0/1]: 0번째부터 i번째 까지 중, i번째 원소를 포함하는 연속 부분 수열의 최대값
    const acc = Array.from({ length: N }, () => {
        return Array.from({ length: 2 }, () => [0, 0]);
    });
    
    for (let i=0; i<N; i++) {
        if (i === 0) {
            pulsed[0][0] = sequence[0];
            pulsed[0][1] = -sequence[0];
            
            acc[i][0] = pulsed[i][0];
            acc[i][1] = pulsed[i][1];
            
            answer = Math.max(answer, acc[i][0], acc[i][1]);
            
            continue;
        }
        
        const sign = i % 2 === 0 ? 1 : -1;
        
        pulsed[i][0] = sign * sequence[i];
        pulsed[i][1] = (-1) * sign * sequence[i];
        
        acc[i][0] = Math.max(acc[i-1][0] + pulsed[i][0], pulsed[i][0]);
        acc[i][1] = Math.max(acc[i-1][1] + pulsed[i][1], pulsed[i][1]);
        
        answer = Math.max(answer, acc[i][0], acc[i][1]);
    }
    
    return answer;
}