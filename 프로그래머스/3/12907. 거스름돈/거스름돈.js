function solution(n, money) {
    const m = money.length;
    const dp = Array.from({ length: n+1 }, () => 0);
    
    // base
    dp[0] = 1;
    
    // for (let i=1; i*money[0]<=n; i++) {
    //     dp[i] = 1;
    // }
    
    // dp
    for (let i=0; i<m; i++) {
        const _money = money[i];
        
        for (let j=_money; j<=n; j++) {
            dp[j] = (dp[j] + dp[j-_money]) % 1_000_000_007;
        }
    }
    
    return dp[n];
// 초기 풀이: 효율성 timeout (15분 소요)
//     // dp[i][j]: 0~i번째를 사용해서 j를 만드는 경우의 수
//     const dp = Array.from({ length: m }, () => {
//         return Array.from({ length: n+1 }, () => 0);
//     });
    
//     // base
//     for (let i=money[0]; i<=n; i++) {
//         if (i % money[0] === 0) {
//             dp[0][i] = 1;
//         } else {
//             dp[0][i] = 0;
//         }
//     }
    
//     // i: i번째 money를 고려하는 경우 (1~100)
//     for (let i=1; i<m; i++) {
//         const cur = money[i];
        
//         // j: 0~i 동전을 이용해 만들어야 하는 수 (1~100,000)
//         for (let j=1; j<=n; j++) {
//             dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1_000_000_007; // 현재 동전을 사용하지 않는 경우
            
//             // k: 현재 동전을 사용하는 경우. (ex) 6: 1x6 or 2x1+1x4 or 2x2+1x2 or 2x3 (1~최대 100,000)
//             for (let k=1; k*cur<j; k++) {
//                 dp[i][j] = (dp[i][j] + dp[i-1][j - k*cur]) % 1_000_000_007;
//             }
            
//             if (j % cur === 0) {
//                 dp[i][j] = (dp[i][j] + 1) % 1_000_000_007;
//             }
//         }
//     }
    
//     return dp[m-1][n];
}