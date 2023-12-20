function solution(clockHands) {
    let answer = Infinity;
    
    const N = clockHands.length;
    const dir = [
        [0, 0],
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0]
    ];
    
    function handleClock(r, c, count, dir = 1) {
        if (r < 0 || c < 0 || r >= N || c >= N) return;
        clockHands[r][c] = (4 + clockHands[r][c] + dir * count) % 4;
    }
    function check() {
        let result = true;
        
        for (let i=0; i<N; i++) {
            for (let j=0; j<N & result; j++) {
                result = clockHands[i][j] === 0;
            }
        }
        
        return result;
    }
    function go(r, c, count) {
        const nr = (c+1 === N) ? r+1 : r,
              nc = (c+1) % N;
        
        if (answer <= count) {
            return;
        }
        if (r === N) {
            if (check()) {
                answer = count;
            }
            return;
        }
        
        const changed = dir.map(([dx, dy]) => [r+dx, c+dy]);
        
        if (r === 0) {
            for (let move = 0; move<4; move++) {
                changed.forEach(([nx, ny]) => {
                    handleClock(nx, ny, move);
                })
                go(nr, nc, count+move);
                changed.forEach(([nx, ny]) => {
                    handleClock(nx, ny, move, -1);
                })
            }
            return;
        }
        if (clockHands[r-1][c] === 0) {
            go(nr, nc, count);
            return;
        }
        const move = 4 - clockHands[r-1][c];
        changed.forEach(([nx, ny]) => {
            handleClock(nx, ny, move);
        })
        go(nr, nc, count+move);
        changed.forEach(([nx, ny]) => {
            handleClock(nx, ny, move, -1);
        });
    }
    
    go(0, 0, 0);
    
    return answer;
}