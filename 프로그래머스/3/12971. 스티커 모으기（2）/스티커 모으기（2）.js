function solution(sticker) {
    let answer = 0;
    
    if (sticker.length === 1) {
        return sticker[0];
    }
    if (sticker.length <= 3) {
        return Math.max(...sticker);
    }
    
    const check = (arr) => {
        const N = arr.length;
        const dp = Array.from({ length: N }, () => 0);
        
        dp[0] = arr[0];
        dp[1] = Math.max(dp[0], arr[1]);
        
        for (let i=2; i<N; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + arr[i]);
        }
        
        return dp[N-1];
    }
    
    const zeroStart = [...sticker];
    zeroStart.pop();
    
    const oneStart = [...sticker];
    oneStart.shift();
    
    answer = Math.max(check(zeroStart), check(oneStart));
    
    return answer;
}