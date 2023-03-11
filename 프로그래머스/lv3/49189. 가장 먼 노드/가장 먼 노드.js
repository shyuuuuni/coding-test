function solution(n, edge) {
    const adj = Array.from(Array(n+1), () => []);
    const dist = Array(n+1).fill(Infinity);
    const q = [];
    
    edge.forEach(([a,b]) => {
        adj[a].push(b);
        adj[b].push(a);
    });
    
    dist[1] = 0;
    q.push([1, dist[1]]);
    
    while(q.length) {
        const [cur, d] = q.shift();
        
        adj[cur].forEach((dest) => {
            if (dist[dest] <= d + 1) {
                return;
            }
            q.push([dest, d+1]);
            dist[dest] = d+1;
        });
    }
    
    dist.shift();
    const max = Math.max(...dist);
    return dist.filter((d) => d === max).length;
}