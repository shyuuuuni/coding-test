// time = 6 -> 6 + 3 + 2개의 작업
// time = 5 -> 5 + 2 + 1개의 작업
// time = 4 -> 4 + 2 + 1개의 작업
// time = 3 -> 3 + 1 + 1개의 작업
// time = 2 -> 2 + 1 + 0개의 작업 = 정답

function solution(n, cores) {
    if (n <= cores.length) {
        return n;
    }
    
    let target = n - cores.length;
    let left = 1, right = target * 10_000;
    
    while (left < right) {
        const mid = Math.floor((left + right) / 2); // time
        const 처리량 = cores.reduce((acc, cur) => acc + Math.floor(mid / cur), 0);
        
        if (target <= 처리량) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    // right : 작업이 모두 처리되는 시점
    // right-1 : 작업이 처리되기 전 시점
    const prev = right - 1;
    cores.forEach((core) => {
        target -= Math.floor((prev / core));
    });
    
    for (let i=0; i<cores.length; i++) {
        const core = cores[i];
        if (right % core === 0) {
            target -= 1;
        }
        if (target === 0) {
            return i+1;
        }
    }
    
    return 0;
}