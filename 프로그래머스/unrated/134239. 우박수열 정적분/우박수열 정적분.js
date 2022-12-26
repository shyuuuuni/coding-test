const collatz = (k) => {
    let n = k;
    const 우박수열 = [];
    
    while (1 <= n) {
        우박수열.push(n);
        if (n === 1) {
            break;
        }
        if (n % 2 === 0) {
            n = n / 2;
            continue;
        }
        n = (n * 3) + 1;
    }
    
    return 우박수열;
}

const prefixSum = (seq) => {
    const 누적합 = [0];
    
    for (let cur=1; cur<seq.length; cur++) {
        const prev = cur-1;
        const y1 = seq[prev], y2 = seq[cur];
        const range = Math.abs(y1 - y2) * 0.5 + Math.min(y1, y2);
        누적합[cur] = 누적합[prev] + range;
    }
    
    return 누적합;
}

function solution(k, ranges) {
    const 우박수열 = collatz(k);
    const 누적합 = prefixSum(우박수열);
    
    return ranges.reduce((acc, [a, b]) => {
        const left = a;
        const right = 누적합.length + b - 1;
                
        if (left <= right) {
            acc.push(누적합[right] - 누적합[left]);
            return acc;
        }
        
        acc.push(-1);
        return acc;
    }, []);
}