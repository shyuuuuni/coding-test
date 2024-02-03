/*
7           0
3 8         0 1
8 1 0       0 1 2
2 7 4 4     0 1 2 3
4 5 2 6 5   0 1 2 3 4
*/

function solution(triangle) {
    for (let i=0; i<triangle.length; i++) {
        if (i === 0) {
            continue;
        }
        
        for (let j=0; j<triangle[i].length; j++) {
            if (j === 0) {
                triangle[i][j] += triangle[i-1][j];
            } else if (j === triangle[i].length-1) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += Math.max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    
    return Math.max(...triangle.pop());
}