function solution(target) {
    const dp = Array.from({ length: target+1 }, () => [Infinity, 0]); // [다트 수, 싱글 수 + 불 수]
    
    
    for (let i=1; i<=target; i++) {
        // base
        if (i <= 20) {
            dp[i] = [1, 1]; // 싱글로 맞춘 경우
            continue;
        }
        if (i <= 60 && i % 3 === 0) {
            dp[i] = [1, 0]; // 트리플로 맞춘 경우
            continue;
        }
        if (i <= 40 && i % 2 === 0) {
            dp[i] = [1, 0]; // 더블로 맞춘 경우
            continue;
        }
        if (i === 50) {
            dp[i] = [1, 1]; // 불로 맞춘 경우
            continue;
        }
        
        // dp from 1~20
        for (let j=1; j<=20; j++) {
            for (let k=1; k<=3; k++) {
                if (i < j*k) {
                    break;
                }
                const acc = dp[i-j*k],
                      add = dp[j*k];
                
                if (acc[0] + add[0] < dp[i][0]) {
                    dp[i] = [acc[0] + add[0], acc[1] + add[1]];
                    continue;
                }
                if (acc[0] + add[0] === dp[i][0] && dp[i][1] < acc[1] + add[1]) {
                    dp[i] = [acc[0] + add[0], acc[1] + add[1]];
                    continue;
                }
            }
        }
        
        // dp from 50
        if (50 <= i) {
            const acc = dp[i-50],
                  add = dp[50];
            
            if (acc[0] + add[0] < dp[i][0]) {
                dp[i] = [acc[0] + add[0], acc[1] + add[1]];
                continue;
            }
            if (acc[0] + add[0] === dp[i][0] && dp[i][1] < acc[1] + add[1]) {
                dp[i] = [acc[0] + add[0], acc[1] + add[1]];
                continue;
            }
        }
    }
    
    return dp[target];
}