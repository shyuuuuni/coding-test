function solution(temperature, t1, t2, a, b, onboard) {
    const N = onboard.length + 1;
    
    // -10도 = 인덱스 1, 0도 = 인덱스 11(OFFSET)
    const OFFSET = 11;
    
    const MIN_TEMP = (-10) + OFFSET; // -10'C
    const MAX_TEMP = 40 + OFFSET; // 40'C
    
    const isInTemperature = (t) => {
        return t1 + OFFSET <= t && t <= t2 + OFFSET;
    }
    
    const dp = Array.from({ length: N + 1 }, () => {
        return Array.from({ length: MAX_TEMP + 2 }, () => Infinity);
    });
    
    // time = 0
    dp[0][temperature + OFFSET] = 0;
    
    for (let time = 1; time <= N; time++) {
        for (let temp = MIN_TEMP; temp <= MAX_TEMP; temp++) {
            if (onboard[time] === 1 && !isInTemperature(temp)) {
                continue;
            }
            
            // 1. (on) temp change
            dp[time][temp] = Math.min(dp[time][temp], dp[time-1][temp-1] + a, dp[time-1][temp+1] + a);
            
            // 2. (on) temp same
            dp[time][temp] = Math.min(dp[time][temp], dp[time-1][temp] + b);
            
            // 3. (off)
            if (temp - 1 < temperature + OFFSET) {
                // temp-1 -> temp 로 1 증가
                dp[time][temp] = Math.min(dp[time][temp], dp[time-1][temp-1]);
            }
            if (temp + 1 > temperature + OFFSET) {
                // temp+1 -> temp 로 1 감소
                dp[time][temp] = Math.min(dp[time][temp], dp[time-1][temp+1]);
            }
            if (temp === temperature + OFFSET) {
                // temp -> temp(외부온도) 유지
                dp[time][temp] = Math.min(dp[time][temp], dp[time-1][temp]);
            }
        }
    }
    
    const answer = Math.min(...dp[N]);
    
    return answer;
}