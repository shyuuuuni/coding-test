function solution(n, info) {
    let answer = [], max = 0;
    
    function caclDiff(arr) {
        // acc[0]: 어피치(info), acc[1]: 라이언
        const sum = arr.reduce((acc, cur, i) => {
            const add = 10 - i;
            
            if (0 < info[i] && cur === 0) {
                acc[0] += add;
            } else if (info[i] === 0 && 0 < cur) {
                acc[1] += add;
            } else if (0 < info[i] && 0 < cur) {
                if (info[i] < cur) {
                    acc[1] += add;
                } else {
                    acc[0] += add;
                }
            }
            return acc;
        }, [0, 0]);
        
        return [sum[0], sum[1]];
    }
    
    function checkOrder(a, b) {
        for (let i=10; 0<=i; i--) {
            if (b[i] < a[i]) {
                return true;
            } else if (a[i] < b[i]) {
                return false;
            }
        }
        return false;
    }
    
    function check(i, rest, arr) {
        if (11 === i) {
            const [a, l] = caclDiff(arr);
            const diff = l - a;
            if (max < diff) {
                answer = [...arr];
                max = diff;
                return;
            }
            
            if (max === diff) {
                const change = checkOrder(arr, answer);
                if (change) {
                    answer = [...arr];
                }
            }
            return;
        }
        
        // 남은 화살로 i점 과녁에 맞출 수 없는 경우
        if (rest <= info[i] && i < 10) {
            return check(i+1, rest, arr);
        } else if (rest <= info[i] && i === 10) {
            arr[10] += rest;
            check(i+1, 0, arr);
            arr[10] -= rest;
            return;
        }
        
        // i점 과녁의 점수를 가져온 경우
        const needs = Math.max(info[i]+1, 1);
        arr[i] = needs;
        rest -= needs;
        check(i+1, rest, arr); // backtracking
        arr[i] -= needs;
        rest += needs;
        
        // i점 과녁의 점수를 가져오지 않는 경우
        check(i+1, rest, arr);
    }
    
    check(0, n, Array(11).fill(0));
    
    if (max <= 0) {
        return [-1];
    }
    
    return answer;
}