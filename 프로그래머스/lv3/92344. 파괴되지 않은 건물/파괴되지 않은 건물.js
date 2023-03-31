// // 정확성 100, 효율성 0
// function solution(board, skill) {
//     let answer = 0;
//     const n = board.length,
//           m = board[0].length;
//     const accsum = Array.from(Array(n+1), () => {
//         return Array.from(Array(m+1), () => 0);
//     });
    
//     skill.forEach(([type, r1, c1, r2, c2, degree]) => {
//         const sign = type === 1 ? -1 : 1;
                
//         // 누적합 추가
//         for (let i=r1; i<=r2; i++) {
//             accsum[i][c1] += sign * degree;
//             accsum[i][c2+1] -= sign * degree;
//         }
//     });
        
//     for (let i=0; i<n; i++) {
//         for (let j=0; j<m; j++) {
//             if (0 < j) {
//                 accsum[i][j] += accsum[i][j-1];
//             }
//             board[i][j] += accsum[i][j];
//             if (0 < board[i][j]) {
//                 answer++;
//             }
//         }
//     }
    
//     return answer;
// }

function solution(board, skill) {
    let answer = 0;
    const n = board.length,
          m = board[0].length;
    const accsum = Array.from(Array(n+1), () => {
        return Array.from(Array(m+1), () => 0);
    });
    
    skill.forEach(([type, r1, c1, r2, c2, degree], i) => {
        const sign = type === 1 ? -1 : 1;

        // 누적합 추가
        accsum[r1][c1] += sign * degree;
        accsum[r2+1][c2+1] += sign * degree;
        accsum[r1][c2+1] -= sign * degree;
        accsum[r2+1][c1] -= sign * degree;
    });
    
    for (let i=0; i<n; i++) {
        for (let j=0; j<m; j++) {
            if (i === 0 && j === 0) {
                // accsum[0][0]
            } else if (i === 0 && 0 < j) {
                accsum[i][j] += accsum[i][j-1];
            } else if (0 < i && j === 0) {
                accsum[i][j] += accsum[i-1][j];
            } else {
                accsum[i][j] += accsum[i][j-1] + accsum[i-1][j] - accsum[i-1][j-1];
            }
            board[i][j] += accsum[i][j];
            if (0 < board[i][j]) {
                answer++;
            }
        }
    }

    return answer;
}