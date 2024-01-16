function solution(n, stations, w) {
    const M = stations.length;
    const func = [];
    
    let answer = 0, // 새롭게 설치한 기지국 수
        j = 0, // check-point
        ptr = 1; // 확인할 아파트
    
    
    const check = (x) => {
        if (M <= j) {
            return [false];
        }
        
        const t = stations[j];
        
        if (t-w <= x && x <= t+w) {
            j++;
            return [true, t+w+1];
        }
        
        return [false];
        
    }
    
    
    while (ptr <= n) {
        const [inRange, next] = check(ptr);
        
        // ptr+w 위치에 기지국 설치 (ptr ~ ptr+w(기지국) ~ ptr+w+w 범위)
        if (!inRange) {
            ptr = ptr + 2*w + 1;
            answer++;
            continue;
        }
        
        // 설치된 자리이므로 다음 위치로 이동
        ptr = next;
    }

    return answer;
}