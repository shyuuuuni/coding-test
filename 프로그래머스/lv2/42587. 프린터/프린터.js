function solution(priorities, location) {
    let cnt = 0;
    const priority = Array(10).fill(0);
    
    priorities.forEach((p) => {
        priority[p]++;
    });
    
    let i = 9;
    const q = priorities.map((p,i) => [p,i]);
    
    while (q.length) {
        const [p, idx] = q[0];
        
        while (priority[i] <= 0 && 0 < i) {
            i--;
        }
        
        q.shift();
        if (p === i) {
            priority[i]--;
            cnt++;
            if (idx === location) {
                return cnt;
            }
        } else {
            q.push([p,idx]);
        }
    }
    
    return 0;
}