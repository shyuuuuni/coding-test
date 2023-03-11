function solution(n, results) {
    // win[i][j]: i가 j를 이길 수 있는가?
    // lose[i][j] : i가 j에게 지는가?
    const win = Array.from(Array(n+1), () => Array(n+1).fill(null));
    // const lose = Array.from(Array(n+1), () => Array(n+1).fill(false));
    
    results.forEach(([winner, loser]) => {
        win[winner][loser] = true;
        // lose[winner][loser] = false;
        win[loser][winner] = false;
        // lose[loser][winner] = true;
    });
    
    for (let i=1; i <= n; i++) {
        win[i][i] = true;
    }
    
    for (let mid = 1; mid <= n; mid++) {
        for (let stt = 1; stt <= n; stt++) {
            for (let end = 1; end <=n; end++) {
                if (win[stt][end] === true) {
                    win[end][stt] = false;
                    continue;
                }
                if ((win[stt][mid] && win[mid][end]) === true) {
                    win[stt][end] = true;
                    win[end][stt] = false;
                }
            }
        }
    }
    
    win.shift();
    return win.filter((loser) => {
        return loser.every((v, i) => {
            if (i === 0) {
                return true;
            }
            if (v !== null) {
                return true;
            }
            return false;
        })
    }).length;
}