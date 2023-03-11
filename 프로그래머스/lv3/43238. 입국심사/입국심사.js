function solution(n, times) {
    times.sort((a,b) => a-b);
    
    let le=times[0],
        ri=times[times.length-1]*n;
    let answer;
    
    function calc(totalTime) {
        return times.reduce((acc, cur) => {
            return acc + Math.floor(totalTime/cur);
        }, 0);
    }
    
    while (le < ri) {
        const mid = Math.floor((le+ri)/2);
        const m = calc(mid);
        
        if (n <= m) {
            answer = mid;
            ri = mid;
        } else {
            le = mid+1;
        }
    }
    
    return answer;
}