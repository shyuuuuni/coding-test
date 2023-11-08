function solution(alp, cop, problems) {
    let maxAlp = 0, maxCop = 0;
    
    for (const [alp_req, cop_req, alp_rwd, cop_rwd, cost] of problems) {
        maxAlp = maxAlp > alp_req ? maxAlp : alp_req;
        maxCop = maxCop > cop_req ? maxCop : cop_req;
    }
    
    // dp 배열 선언
    const dp = Array.from({ length: maxAlp + 1}, () => {
        return Array.from({ length: maxCop + 1 }, () => 9999);
    });
    
    alp = alp > maxAlp ? maxAlp : alp;
    cop = cop > maxCop ? maxCop : cop;
    
    dp[alp][cop] = 0;
    
    for (let i=alp; i<=maxAlp; i++) {
        for (let j=cop; j<=maxCop; j++) {
            if (0 < i) {
                dp[i][j] = dp[i][j] < dp[i-1][j] + 1 ? dp[i][j] : dp[i-1][j] + 1;
            }
            if (0 < j) {
                dp[i][j] = dp[i][j] < dp[i][j-1] + 1 ? dp[i][j] : dp[i][j-1] + 1;
            }
            if (i === maxAlp && j === maxCop) {
                break;
            }
            for (const [alp_req, cop_req, alp_rwd, cop_rwd, cost] of problems) {
                if (i < alp_req || j < cop_req) {
                    continue;
                }
                const a = maxAlp < i + alp_rwd ? maxAlp : i + alp_rwd;
                const c = maxCop < j + cop_rwd ? maxCop : j + cop_rwd;
                
                dp[a][c] = dp[a][c] < dp[i][j] + cost ? dp[a][c] : dp[i][j] + cost;
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}