function nextPermutation(arr) {
    let i = arr.length - 2,
        j = arr.length - 1;

    // 오름차순이 유지되는 가장 큰 인덱스 i를 계산
    while (arr[i + 1] <= arr[i]) {
        i--;
    }
    // i+1 인덱스부터는 내림차순 정렬인 상태, i가 음수면 내림차순(종료)
    if (i < 0) {
        return false;
    }

    // 내림차순인 부분에서 arr[i] < arr[j] 를 만족하는 가장 큰 인덱스 j를 계산
    while (arr[j] <= arr[i]) {
        j--;
    }

    // arr[i]와 arr[j] 를 교환
    [arr[i], arr[j]] = [arr[j], arr[i]];

    // 내림차순이던 부분(i+1 인덱스부터) 을 reverse해서 다음 순열로 변경
    const next = arr.slice(i + 1).reverse();
    arr.splice(i + 1, next.length, ...next);

    return arr;
}

function solution(relation) {
    let answer = 0, n = relation.length, m = relation[0].length;
    let flag = false;
    
    const unique = [], minimum = [];
    
    for (let i=1; i <= m && answer === 0; i++) {
        let arr = Array.from(Array(m), (_,j) => {
            if (m - i <= j) {
                return 1;
            } else {
                return 0;
            }
        });
        
        do {
            const set = new Set();
            
            const str = relation.map((r) => {
                return r.filter((_,i) => {
                    return arr[i];
                }).map((s,i) => {
                    return `${s}/${i}`;
                }).join('-');
            });
            
            let flag = true;
            for(let j=0; j<str.length && flag; j++) {
                if (set.has(str[j])) {
                    flag = false;
                    break;
                }
                set.add(str[j]); 
            }
            if (flag) {
                unique.push(arr.join(''));
            }
        } while(nextPermutation(arr));
    }
    
    const check = Array(unique.length).fill(0);
    for (let i=0; i<unique.length; i++) {
        if (check[i] === -1) {
            continue;
        }
        if (!check[i]) {
            check[i] = 1;
            for (let j=i+1; j<unique.length; j++) {
                if (check[j] === -1) {
                    continue;
                }
                const a = parseInt(unique[i], 2);
                const b = parseInt(unique[j], 2);
                
                if ((a & b) === a) {
                    check[j] = -1;
                }
            }
        }
    }
    
    answer = check.reduce((acc, cur, i) => {
        if (cur === 1) {
            return acc + 1;
        }
        return acc;
    }, 0)
    
    return answer;
}