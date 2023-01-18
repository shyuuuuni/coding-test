
const 제자리클릭 = 1;
const 상하좌우클릭 = 2;
const 대각클릭 = 3;

const 좌표 = new Map([
    [1, [0,0]],
    [2, [0,1]],
    [3, [0,2]],
    [4, [1,0]],
    [5, [1,1]],
    [6, [1,2]],
    [7, [2,0]],
    [8, [2,1]],
    [9, [2,2]],
    [0, [3,1]],
])

const calcDistance = ([fx, fy], [tx, ty]) => {
    const diffX = Math.abs(fx-tx);
    const diffY = Math.abs(fy-ty);

    if (fx === tx && fy === ty) {
        return 제자리클릭;
    }
    if (diffX === diffY) {
        return Math.abs(fx-tx) * 대각클릭;
    }
    if (diffX < diffY) {
        return (diffY - diffX) * 상하좌우클릭 + diffX * (대각클릭);
    }
    return (diffX - diffY) * 상하좌우클릭 + diffY * (대각클릭);

    return distance;
}

function solution(numbers) {
    const N = numbers.length;
    const nums = [0,1,2,3,4,5,6,7,8,9];
    
    // 가중치[i][j]: i->j 이동 시 필요한 최소 가중치
    const 가중치 = [...nums].map((from) => {
        const f = 좌표.get(from);
        return [...nums].reduce((acc, to) => {
            const t = 좌표.get(to);
            acc.push(calcDistance(f, t));
            return acc;
        }, []);
    })
    
    // dp[i][j][k]: i번째 숫자키를 누르면서, 손의 위치 왼손(j), 오른손(k) 일때 최소 가중치
    // = min(dp[i-1][left][k] + 가중치[left][j], dp[i-1][j][right] + 가중치[right][k]
    const dp = Array.from({length:N+1}, () => {
        return Array.from({length:10}, () => {
            return Array.from({length:10}, () => Infinity)
        })
    });
    dp[0][4][6] = 0;
    
    for (let i=1; i<=N; i++) {
        const target = Number(numbers[i-1]);
        
        for (let j=0; j<10; j++) {
            for (let k=0; k<10; k++) {
                if (j === k) {
                    continue;
                }
                if (!isFinite(dp[i-1][j][k])) {
                    continue;
                }
                dp[i][target][k] = Math.min(dp[i][target][k], dp[i-1][j][k] + 가중치[j][target]);
                dp[i][j][target] = Math.min(dp[i][j][target], dp[i-1][j][k] + 가중치[k][target]);
            }
        }
    }
    
    return Math.min(...dp[N].flatMap((x) => [...x]));
}