function solution(places) {
    const dx = [1, 0, -1, 0];
    const dy = [0, 1, 0, -1];
    
    const answer = places.map((place) => {
        const N = 5;
        
        const start = [];
        for (let i=0; i<N; i++) {
            for (let j=0; j<N; j++) {
                if (place[i][j] === 'P') {
                    start.push([i, j]);
                }
            }
        }
        
        for (let i=0; i<start.length; i++) {
            const [x, y] = start[i];
            const queue = [];
            const visited = Array.from({ length: N }, () => {
                return Array.from({ length: N }, () => {
                    return false;
                })
            });
            queue.push([x, y, 0]);
            visited[x][y] = true;
            
            while (queue.length > 0) {
                const [xx, yy, dist] = queue.shift();

                if (dist > 2) {
                    continue;
                }

                for (let i=0; i<4; i++) {
                    const nx = xx + dx[i];
                    const ny = yy + dy[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                        continue;
                    }
                    if (place[nx][ny] === 'X' || visited[nx][ny]) {
                        continue;
                    }
                    if (place[nx][ny] === 'P' && dist < 2) {
                        return 0;
                    }
                    queue.push([nx, ny, dist+1]);
                    visited[nx][ny] = true;
                }
            }
        }
        
        return 1;
    });
    
    
    return answer;
}