function solution(n) {
    // dp[i] : i 쌍의 가짓수로 만든 괄호쌍 수
    const dp = Array.from({ length: n + 1 }, () => {
        return 0;
    });
    
    dp[0] = 1;
    dp[1] = 1;
    
    for (let i=2; i<=n; i++) {
        for (let j=0; j<i; j++) {
            // DP[i] = Sigma( (DP[j]) * DP[i-j-1] ) - 기본적으로 왼쪽에 괄호가 하나 추가
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    
    return dp[n];
}