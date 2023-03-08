function solution(maps) {
    const dx = [0, 1, 0, -1],
          dy = [1, 0, -1, 0];
    const N = maps.length,
          M = maps[0].length;
    const visited = Array.from({ length: N }, () => {
        return Array.from({ length: M }, () => 0);
    });
    const queue = [];
    
    visited[0][0] = 1;
    queue.push([0,0]);
    
    while(0 < queue.length) {
        const [x, y] = queue.shift();
        const dist = visited[x][y];
        
        for (let i=0; i<4; i++) {
            const [nx, ny] = [x + dx[i], y + dy[i]];
            
            if (nx < 0 || ny < 0 || N <= nx || M <= ny) {
                continue;
            }
            if (maps[nx][ny] === 0 || 0 < visited[nx][ny]) {
                continue;
            }
            
            visited[nx][ny] = dist + 1;
            queue.push([nx, ny]);
        }
    }
    
    if (visited[N-1][M-1] === 0) {
        return -1;
    }
    return visited[N-1][M-1];
}