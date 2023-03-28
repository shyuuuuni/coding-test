// 사전순: d - l - r - u
function solution(n, m, x, y, r, c, k) {
    const answer = [];
    const next = [
        [1, 0, 'd'],     // d
        [0, -1, 'l'],    // l
        [0, 1, 'r'],     // r
        [-1, 0, 'u']     // u
    ];
    const stack = [];
    const getdist = (stt, end) => {
        const [sx, sy] = stt,
              [ex, ey] = end;
        return Math.abs(sx - ex) + Math.abs(sy - ey);
    }
    
    // dfs
    stack.push({
        x,          // 세로
        y,          // 가로
        s: ""       // 문자열
    });
    while (stack.length) {
        const ptr = stack.pop();
        const dist = ptr.s.length;
        
        if (dist === k && ptr.x === r && ptr.y === c) {
            return ptr.s;
        }
        if (k <= dist) {
            continue;
        }
        
        for (let i=0; i<4; i++) {
            const [nx, ny] = [ptr.x + next[i][0], ptr.y + next[i][1]];
            if (nx <= 0 || ny <= 0 || n < nx || m < ny) {
                continue;
            }
            if (k < dist + getdist([nx,ny], [r,c]) + 1) {
                continue;
            }
            stack.push({
                x: nx,
                y: ny,
                s: ptr.s.concat(next[i][2]),
            });
            break;
        }
    }
    
    return "impossible";
}