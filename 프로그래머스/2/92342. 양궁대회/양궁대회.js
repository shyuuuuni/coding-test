function solution(n, info) {
    let best = 0,
        answer = null;
    
    const N = 10;
    
    function check(arr) {
        let cur = 0;
        
        for (let i=0; i<=N; i++) {
            const score = 10-i;
            
            if (info[i] === 0 && arr[i] === 0) continue;
            if (info[i] >= arr[i]) cur -= score;
            else cur += score;
        }
        
        if (cur <= 0) {
            return;
        }
        if (cur > best) {
            best = cur;
            answer = [...arr];
            return;
        }
        if (cur === best) {
            for (let i=N; i>=0; i--) {
                if (answer[i] === arr[i]) continue;
                if (answer[i] < arr[i]) {
                    best = cur;
                    answer = [...arr];
                }
                return;
            }
        }
    }
    
    function go(idx, amount, arr) {
        if (N < idx) {
            check(arr);
            return;
        }
        for (let i=0; i<=amount; i++) {
            arr[idx] += i;
            go(idx+1, amount-i, arr);
            arr[idx] -= i;
        }
        
        return;
    }
    
    go(0, n, Array.from({ length: N+1 }, () => 0));
    
    if (answer === null) {
        return [-1];
    }
    
    return answer;
}