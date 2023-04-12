// 11:00~
function solution(n, build_frame) {
    const answer = [];
    
    const building = Array.from({ length: 2 }, () => { // 기둥(0), 보(1)
        return Array.from({ length: n+2 }, () => {
            return Array.from({ length: n+2 }, () => 0);
        });
    });
    
    function remove(x, y, a, b) {
        let success = true;
        
        for (let type=0; type<2 && success; type++) {
            for (let i=0; i<n+1 && success; i++) { // x
                for (let j=0; j<n+1 && success; j++) { // y
                    if (!building[type][i][j]) {
                        continue;
                    }
                    if (type === 0) {
                        if (j === 0) {
                            continue;
                        } else if (i === 0 && !building[0][i][j-1] && !building[1][i][j]) {
                            console.log("!1");
                            success = false;
                        } else if (i !== 0 && !building[1][i-1][j] && !building[1][i][j] && !building[0][i][j-1]) {
                            console.log("!2");
                            success = false;
                        }
                    } else {
                        if (j === 0) {
                            continue;
                        } else if (i === 0 && !building[0][i][j-1] && !building[0][i+1][j-1]) {
                            console.log("!3");
                            success = false;
                        } else if (i !== 0 && !((building[1][i-1][j] && building[1][i+1][j]) || (building[0][i][j-1] || building[0][i+1][j-1]))) {
                            success = false;
                        }
                    }
                    
                }
            }
        }

        return success;
    }
    
    build_frame.forEach(([x,y,a,b]) => {
        if (b === 0) { // 삭제
            building[a][x][y] = 0;
            if (!remove(x,y,a,b)) {
                building[a][x][y] = 1;
            }
        } else { // 추가
            if (a === 0) { // 추가-기둥
                if (y === 0 || building[0][x][y-1]) {
                    building[0][x][y] = 1;
                } else if (building[1][x][y] || (x !== 0 && building[1][x-1][y])) {
                    building[0][x][y] = 1;
                }
            } else { // 추가-보
                if (y !== 0 && (building[0][x][y-1] || building[0][x+1][y-1])) {
                    building[1][x][y] = 1;
                } else if (x !== 0 && building[1][x-1][y] && building[1][x+1][y]) {
                    building[1][x][y] = 1;
                } 
            }
        }
    });

    for (let i=0; i<2; i++) {
        for (let j=0; j<n+2; j++) {
            for (let k=0; k<n+2; k++) {
                if (building[i][j][k]) {
                    answer.push([j,k,i]);
                }
            }
        }
    }
    
    answer.sort((a,b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        } else if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    })
    
    return answer;
}