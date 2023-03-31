function solution(info, edges) {
    let answer = 0;
    
    const n = info.length;
    const connect = Array.from(Array(n), () => {
        return Array.from(Array(n), () => false);
    });
    
    edges.forEach(([a,b]) => {
        connect[a][b] = true;
    });
    
    function dfs(cur, count, wolf, next) {
        if (answer < count) {
            answer = count;
        }
        
        const visitable = [];
        for (let i=0; i<n; i++) {
            if (!connect[cur][i]) {
                continue;
            }
            visitable.push(i);
        }
        
        next = [...next, ...visitable];
        for (let n of next) {
            if (info[n] === 0) {
                dfs(n, count+1, wolf, next.filter((x) => x != n));
            } else if (wolf + 1 < count) {
                dfs(n, count, wolf+1, next.filter((x) => x != n));
            }
        }
    }
    
    dfs(0, 1, 0, [], []);
    
    return answer;
}