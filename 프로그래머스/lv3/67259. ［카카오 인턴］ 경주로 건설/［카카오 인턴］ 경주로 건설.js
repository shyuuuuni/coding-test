class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}
class Queue {
    constructor() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }
    push(value) {
        const node = new Node(value);
        if (this.size === 0) {
            this.first = node;
            this.last = node;
            this.size++;
            return node;
        }
        this.last.next = node;
        this.last = node;
        this.size++;
        return node;
    }
    pop() {
        if (this.size === 0) {
            return undefined;
        }
        const value = this.first.value;
        if (this.size === 1) {
            this.first = null;
            this.last = null;
            this.size--;
            return value;
        }
        this.first = this.first.next;
        this.size--;
        return value;
    }
}

function solution(board) {
    const d = {
        up: 0,
        left: 1,
        down: 2,
        right: 3
    };
    const straight = [
        [-1, 0],
        [0, -1],
        [1, 0],
        [0, 1]
    ];
    const curve = [
        [[0, -1], [0, 1]],
        [[1, 0], [-1, 0]],
        [[0, 1], [0, -1]],
        [[-1, 0], [1, 0]]
    ];

    const N = board.length,
          M = board[0].length;
    // dp[i][j][dir] : dir방향을 보고 있는 (i,j) 위치까지의 최소 비용
    const dp = Array.from(Array(N), () => {
        return Array.from(Array(M), () => {
            return Array.from(Array(4), () => Infinity)
        });
    });
    
    const queue = new Queue();
    
    dp[0][0][d.right] = 0;
    dp[0][0][d.down] = 0;
    queue.push({
        x: 0,
        y: 0,
        dir: d.right,
        val: 0
    });
    queue.push({
        x: 0,
        y: 0,
        dir: d.down,
        val: 0
    });
    
    while (queue.size) {
        const { x, y, dir, val } = queue.pop();
        
        // 다른 방법으로 갱신된 상태 or 최종 비용보다 비싼 경우
        if (dp[x][y][dir] < val || Math.min(...dp[N-1][M-1]) <= val) {
            continue;
        }
        
        // for (let i=0; i<4; i++) 위아래왼쪽오른쪽 다 때려도 될듯
        
        // 직진
        const [sx, sy] = [x + straight[dir][0], y + straight[dir][1]];
        const sval = val + 100;
        if (!(sx < 0 || sy < 0 || N <= sx || M <= sy) && board[sx][sy] === 0 && sval <= dp[sx][sy][dir]) {
            // console.log(`s (${x},${y} -> (${sx}, ${sy}) with ${dir}, ${sval}won`);
            dp[sx][sy][dir] = sval;
            if (!(sx === N-1 && sy === M-1)) {
                queue.push({
                    x: sx,
                    y: sy,
                    dir,
                    val: sval
                });                
            }
        }
        
        // 커브
        const cval = val + 600;
        for (let i=0; i<2; i++) {
            const cdir = ((dir + (2*i) + 1) % 4);
            const [cx, cy] = [x + curve[dir][i][0], y + curve[dir][i][1]];
            if (!(cx < 0 || cy < 0 || N <= cx || M <= cy) && board[cx][cy] === 0 && cval <= dp[cx][cy][cdir]) {
                // console.log(`c (${x},${y} -> (${cx}, ${cy}) with ${dir} -> ${cdir}, ${cval}won`);
                dp[cx][cy][cdir] = cval;
                if (!(sx === N-1 && sy === M-1)) {
                    queue.push({
                        x: cx,
                        y: cy,
                        dir: cdir,
                        val: cval
                    });
                }
            }
        }
    }

    return Math.min(...dp[N-1][M-1]);
}