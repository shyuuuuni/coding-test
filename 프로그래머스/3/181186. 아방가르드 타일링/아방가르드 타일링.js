function solution(n) {
    const dp = Array.from({ length: n + 1 }, () => 0);
    const uniqueCase = [
        [4, 2, 2], // n = 3, 6, 9, ...
        [2, 4, 2], // n = 4, 7, 10, ...
        [2, 2, 4], // n = 5, 8, 11, ...
    ]
    
    // 3->0, 4->1, ...
    function getUnique(number, i) {
        const u = uniqueCase[number % 3];
        
        return u[i];
    }
    
    // base
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    
    // prefix sum
    const acc = [0, 0, 0]; // 각각 2, 2, 4를 곱할 수의 합   
    
    // dp
    for (let i=4; i<=n; i++) {
        const accIndex = (i-4) % 3;
        const accItem = dp[i-4];
        
        // 동일한 uniqueCase를 가지는 집합의 누적합 증가
        acc[accIndex] = (acc[accIndex] + accItem) % 1_000_000_007;
        
        dp[i] = (dp[i] + 1 * dp[i-1] + 2 * dp[i-2] + 5 * dp[i-3]) % 1_000_000_007;
        dp[i] = (dp[i] + acc[0] * getUnique(i, 0) + acc[1] * getUnique(i, 1) + acc[2] * getUnique(i, 2)) % 1_000_000_007;
    }
    
    return dp[n];
}