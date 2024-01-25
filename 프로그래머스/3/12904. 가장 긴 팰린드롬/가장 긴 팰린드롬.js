function solution(s) {
    let answer = 0;
    
    const n = s.length;
    
    // dp[i][j]: i~j 문자열 내에 포함된 최대 팰린드롬의 길이
    const dp = Array.from({ length: n+1 }, () => {
        return Array.from({ length: n+1 }, () => 0);
    });
    
    // base
    for (let i=0; i<n; i++) {
        dp[i][i] = 1; // 본인만 포함된 팰린드롬
    }
    
    // dp
    for (let window=1; window<n; window++) {
        for (let i=0; i+window<n; i++) {
            const j = i+window;
            
            if (window === 1 && s[i] === s[j]) {
                dp[i][j] = window+1;
            } else if (s[i] === s[j] && 0 < dp[i+1][j-1]) {
                dp[i][j] = window+1;
            }
        }
    }
    
    for (let i=0; i<n; i++) {
        for (let j=0; j<n; j++) {
            if (answer < dp[i][j]) {
                answer = dp[i][j];
            }
        }
    }

    return answer;
}