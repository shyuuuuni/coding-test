function solution(places) {
    const answer = [],
          MIN_DIST = 3; // 3이상 떨어져서 앉기
    const dx = [1, 0, -1, 0],
          dy = [0, 1, 0, -1];
    
    function getCheckedArray() {
        return Array.from(Array(5), () => Array.from(Array(5), () => false));
    }
    function isInBound(x, y, N, M) {
        return (0 <= x && 0 <= y && x < N && y < M);
    }
    function checkWaitingRoom(place, N, M) {
        let flag = 1;
        
        for (let i=0; i<N && flag; i++) {
            for (let j=0; j<M && flag; j++) {
                if (place[i][j] !== 'P') {
                    continue;
                }
                const checked = getCheckedArray(),
                      queue = [];
                checked[i][j] = true;
                queue.push({ x: i, y: j, d: 0 });

                while (0 < queue.length) {
                    const { x, y, d } = queue.shift();
                    
                    if (MIN_DIST <= d+1) {
                        continue;
                    }

                    for (let k=0; k<4; k++) {
                        const nx = x + dx[k],
                              ny = y + dy[k];
                        
                        // fail
                        if (!isInBound(nx, ny, N, M)) {
                            continue;
                        }
                        if (checked[nx][ny] || place[nx][ny] === 'X') {
                            continue;
                        }
                        // sucess
                        if (place[nx][ny] === 'P') {
                            flag = 0;
                        }
                        checked[i][j] = true;
                        queue.push({ x: nx, y: ny, d: d+1 })
                    }
                }
            }
        }
        
        answer.push(flag);
    }
    
    places.forEach((place) => {
        const M = place.length, // 가로
              N = place[0].length; // 세로
        checkWaitingRoom(place, N, M);
    })
    
    
    return answer;
}