function solution(m, n, puddles) {
    const dp = Array.from({ length: n+1 }, () => {
        return Array.from({ length: m+1 }, () => {
            return 0;
        });
    });
    const isPuddle = Array.from({ length: n+1 }, () => {
        return Array.from({ length: m+1 }, () => {
            return false;
        });
    });
    for (let [x, y] of puddles) {
        isPuddle[y][x] = true;
    }
    
    dp[1][1] = 1;
    for (let i=1; i<=n; i++) {
        for (let j=1; j<=m; j++) {
            if (isPuddle[i][j]) {
                continue;
            }
            if (!isPuddle[i-1][j]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1_000_000_007;
            }
            if (!isPuddle[i][j-1]) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1_000_000_007;
            }
        }
    }
    
    return dp[n][m];
}