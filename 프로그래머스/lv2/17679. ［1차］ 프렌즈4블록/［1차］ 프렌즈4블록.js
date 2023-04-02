const dx = [1, 0, -1, 0],
      dy = [0, 1, 0, -1];

function solution(m, n, board) {
    let answer = 0;
    board = board.map((str) => str.split(''));
    
    function isValid(x, y) {
        if (x<0 || y<0 || m<=x || n<=y) {
            return false;
        }
        return true;
    }
    
    function check(x, y, remove) {
        const origin = board[x][y];
        let flag = true;
        
        for (let i=x; i<x+2; i++) {
            for (let j=y; j<y+2; j++) {
                if (board[i][j] !== origin) {
                    flag = false;
                }
            }
        }
        
        if (!flag) {
            return false;
        }
        
        for (let i=x; i<x+2; i++) {
            for (let j=y; j<y+2; j++) {
                remove[i][j] = true;
            }
        }
        return true;
    }
    
    function removeBlocks() {
        const remove = Array.from(Array(m), () => {
            return Array.from(Array(n), () => false);
        });
        let removed = 0;
        
        for (let i=0; i<m; i++) {
            for (let j=0; j<n; j++) {
                if (!isValid(i+1, j+1)) {
                    continue;
                }
                if (!board[i][j]) {
                    continue;
                }
                check(i, j, remove);
            }
        }
        
        for (let i=0; i<m; i++) {
            for (let j=0; j<n; j++) {
                if (remove[i][j]) {
                    removed++;
                    board[i][j] = null;
                }
            }
        }
        
        return removed;
    }
    
    function dropDown() {
        for (let i=0; i<n; i++) { // 가로 방향으로
            const stack = [];
            for (let j=0; j<m; j++) {
                if (board[j][i]) {
                    stack.push(board[j][i]);
                    board[j][i] = null;
                }
            }
            for (let j=m-1; 0<=j && stack.length; j--) {
                board[j][i] = stack.pop();
            }
        }
    }
    
    
    while (true) {
        const removed = removeBlocks();
        if (removed === 0) {
            break;
        }
        answer += removed;
        dropDown();
    }
    
    return answer;
}