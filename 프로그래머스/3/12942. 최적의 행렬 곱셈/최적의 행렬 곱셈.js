function solution(matrix_sizes) {
    const N = matrix_sizes.length;
    
    // dp[i][j]: 연쇄행렬 i~j를 곱했을 때 최소 곱셈 수
    const dp = Array.from({ length: N }, () => {
        return Array.from({ length: N }, () => {
            return Infinity;
        });
    });
    
    for (let i=0; i<N; i++) {
        dp[i][i] = 0;
    }
    
    for (let window=1; window<N; window++) {
        for (let i=0; i+window<N; i++) {
            const leftStart = i,
                  rightEnd = i+window;
            
            for (let j=0; i+j<rightEnd; j++) {
                const leftEnd = i+j,
                      rightStart = i+j+1;
                const a = matrix_sizes[leftStart][0],
                      b = matrix_sizes[leftEnd][1],
                      c = matrix_sizes[rightEnd][1];
                
                dp[leftStart][rightEnd] = Math.min(dp[leftStart][rightEnd], dp[leftStart][leftEnd] + dp[rightStart][rightEnd] + a*b*c);
            }
        }
    }
    
    return dp[0][N-1];
}