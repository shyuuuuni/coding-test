function solution(maze) {
    let answer = Infinity;
    
    const DIR = {
        x: [0, 1, 0, -1, 0],
        y: [1, 0, -1, 0, 0],
    };
    const MAZE_STATUS = {
        빈칸: 0,
        빨강: 1, // 01
        파랑: 2, // 10
        빨강_도착: 3,
        파랑_도착: 4,
        벽: 5,
    };
    const VISITED_STATUS = {
        방문전: 0, // 00
        빨강_방문: 1, // 01
        파랑_방문: 2, // 10
        둘_다_방문: 3, // 11
    };
    const N = maze.length, // 세로
          M = maze[0].length; // 가로
    const visited = Array.from({ length: N }, () => {
        return Array.from({ length: M }, () => VISITED_STATUS.방문전);
    });
    const red = {
        x: 0,
        y: 0,
        end: [0, 0],
    };
    const blue = {
        x: 0,
        y: 0,
        end: [0, 0],
    };
        
    for (let i=0; i<N; i++) {
        for (let j=0; j<M; j++) {
            if (maze[i][j] === MAZE_STATUS.빨강) {
                red.x = i;
                red.y = j;
                continue;
            }
            if (maze[i][j] === MAZE_STATUS.파랑) {
                blue.x = i;
                blue.y = j;
                continue;
            }
            if (maze[i][j] === MAZE_STATUS.빨강_도착) {
                red.end = [i, j];
                continue;
            }
            if (maze[i][j] === MAZE_STATUS.파랑_도착) {
                blue.end = [i, j];
                continue;
            }
        }
    };
    
    function isVisitable(x, y, user, visited) {
        return (visited[x][y] & user) === 0;
    }
    
    function isOutOfBound(n, m, x, y) {
        return x < 0 || y < 0 || n <= x || m <= y;
    }
    
    function isSame(ax, ay, bx, by) {
        return ax === bx && ay === by;
    }
    
    function solve(red, blue, visited, turn) {
        const { x: redX, y: redY, end: [redEndX, redEndY] } = red;
        const { x: blueX, y: blueY, end: [blueEndX, blueEndY] } = blue;

        if (answer <= turn) {
            return Infinity;
        }
        if (redX === redEndX && redY === redEndY && blueX === blueEndX && blueY === blueEndY) {
            answer = turn;
            return turn;
        }
        
        for (let i=0; i<5; i++) {
            for (let j=0; j<5; j++) {
                const nextRedX = redX + DIR.x[i],
                      nextRedY = redY + DIR.y[i],
                      nextBlueX = blueX + DIR.x[j],
                      nextBlueY = blueY + DIR.y[j];
                
                const isRedEnd = isSame(redX, redY, redEndX, redEndY),
                      isBlueEnd = isSame(blueX, blueY, blueEndX, blueEndY);
                
                if (isRedEnd && i !== 4) {
                    continue;
                }
                if (isBlueEnd && j !== 4) {
                    continue;
                }
                // 올바르지 않은 좌표
                if (isOutOfBound(N, M, nextRedX, nextRedY) || isOutOfBound(N, M, nextBlueX, nextBlueY)) {
                    continue;
                }
                // 동시에 같은곳으로 도착
                if (isSame(nextRedX, nextRedY, nextBlueX, nextBlueY)) {
                    continue;
                }
                // 교차하여 이동
                if (isSame(nextRedX, nextRedY, blueX, blueY) && isSame(nextBlueX, nextBlueY, redX, redY)) {
                    continue;
                }
                // 벽 확인
                if (maze[nextRedX][nextRedY] === MAZE_STATUS.벽 || maze[nextBlueX][nextBlueY] === MAZE_STATUS.벽) {
                    continue;
                }
                // 방문 기록 확인
                if ((!isRedEnd && !isVisitable(nextRedX, nextRedY, MAZE_STATUS.빨강, visited)) || (!isBlueEnd && !isVisitable(nextBlueX, nextBlueY, MAZE_STATUS.파랑, visited))) {
                    continue;
                }
                
                // 업데이트
                if (!isRedEnd) {
                    maze[redX][redY] = MAZE_STATUS.빈칸;
                    // visited[redX][redY] = visited[redX][redY] ^ MAZE_STATUS.빨강;
                    maze[nextRedX][nextRedY] = MAZE_STATUS.빨강;
                    visited[nextRedX][nextRedY] = visited[nextRedX][nextRedY] ^ MAZE_STATUS.빨강;

                    red.x = nextRedX;
                    red.y = nextRedY;
                }
                if (!isBlueEnd) {
                    maze[blueX][blueY] = MAZE_STATUS.빈칸;
                    // visited[blueX][blueY] = visited[blueX][blueY] ^ MAZE_STATUS.파랑;
                    maze[nextBlueX][nextBlueY] = MAZE_STATUS.파랑;
                    visited[nextBlueX][nextBlueY] = visited[nextBlueX][nextBlueY] ^ MAZE_STATUS.파랑;

                    blue.x = nextBlueX;
                    blue.y = nextBlueY;
                }
                
                // DFS
                solve(red, blue, visited, turn+1);
                
                // 업데이트 취소
                if (!isRedEnd) {
                    maze[redX][redY] = MAZE_STATUS.빨강;
                    // visited[redX][redY] = visited[redX][redY] ^ MAZE_STATUS.빨강;
                    maze[nextRedX][nextRedY] = MAZE_STATUS.빈칸;
                    visited[nextRedX][nextRedY] = visited[nextRedX][nextRedY] ^ MAZE_STATUS.빨강;
                    
                    red.x = redX;
                    red.y = redY;
                }
                if (!isBlueEnd) {
                    maze[blueX][blueY] = MAZE_STATUS.파랑;
                    // visited[blueX][blueY] = visited[blueX][blueY] ^ MAZE_STATUS.파랑;
                    maze[nextBlueX][nextBlueY] = MAZE_STATUS.빈칸;
                    visited[nextBlueX][nextBlueY] = visited[nextBlueX][nextBlueY] ^ MAZE_STATUS.파랑;

                    blue.x = blueX;
                    blue.y = blueY;
                }
            }
        }
    }
    
    visited[red.x][red.y] = MAZE_STATUS.빨강;
    visited[blue.x][blue.y] = MAZE_STATUS.파랑;
    
    solve(red, blue, visited, 0);
    
    if (answer === Infinity) {
        return 0;
    }
    
    return answer;
}