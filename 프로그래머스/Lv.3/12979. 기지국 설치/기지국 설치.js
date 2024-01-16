function solution(n, stations, w) {
    let answer = 0;
    let j = 0; // check-point
    
    const M = stations.length;
    const set = new Set(stations);
    
    const func = [];
        
    for (let i=0; i<M; i++) {
        const t = stations[i];
        const f = (x) => {
            return t-w <= x && x <= t+w;
        }
        func.push(f);
    }
    
    const check = (x) => {
        let inRange = false,
            next = null;
        
        for (let i=j; i<M; i++) {
            const t = stations[i];
            const f = func[i];
            
            if (f(x)) {
                inRange = true;
                next = t+w+1;
                j = i+1;
            }
            
            break;
        }
        
        return [inRange, next];
    }
    
    let ptr = 1;
    
    while (ptr <= n) {
        const [inRange, next] = check(ptr);
        
        // ptr+w 위치에 기지국 설치 (ptr ~ ptr+w(기지국) ~ ptr+w+w 범위)
        if (!inRange) {
            ptr = ptr+2*w+1;
            answer++;
            continue;
        }
        
        // 설치된 자리이므로 다음 위치로 이동
        ptr = next;
    }

    return answer;
}