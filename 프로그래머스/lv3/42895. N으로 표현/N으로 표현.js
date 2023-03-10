function solution(N, number) {
    // dp[i]: N을 i번 사용해서 만들 수 있는 수의 집합
    const dp = Array.from({length: 9}, () => new Set());
    
    for (let i=1; i<=8; i++) {
        dp[i].add(Number(`${N}`.repeat(i)));
    }
    
    for (let i=2; i<=8; i++) {
        const cur = dp[i];
        for (let j=1; j<i; j++) {
            const k = i-j;
            
            const p1 = [...dp[j]],
                  p2 = [...dp[k]];
            
            p1.forEach((v1) => {
                p2.forEach((v2) => {
                    cur.add(v1 + v2);
                    cur.add(v1 - v2);
                    cur.add(Math.floor(v1 / v2));
                    cur.add(v1 * v2);
                })
            });
        }
    }

    for (let i=1; i<=8; i++) {
        if (dp[i].has(number)) {
            return i;
        }
    }
    
    return -1;
}