function solution(id_list, report, k) {
    const N = id_list.length;
    const answer = Array.from({ length: N }, () => {
        return [0, 0];
    });
    const convert = new Map();
    const reportCount = new Map();
    const reported = Array.from({ length: N }, () => {
        return Array.from({ length: N }, () => {
            return false;
        });
    });
    
    id_list.forEach((id, i) => convert.set(id, i));
    
    report.forEach((r) => {
        const [from, to] = r.split(" ");
        const [fromI, toI] = [convert.get(from), convert.get(to)];
        
        if (!reportCount.has(toI)) {
            reportCount.set(toI, 0);
        }
        if (reported[fromI][toI]) {
            return;
        }
        
        const prev = reportCount.get(toI);
        reportCount.set(toI, prev+1);
        reported[fromI][toI] = true;
    });
    
    Array.from(reportCount).forEach(([toI, rCount]) => {
        console.log(toI, rCount);
        
        if (k <= rCount) {
            // 정지 메일
            answer[toI][1] = 1;
            
            for (let i=0; i<N; i++) {
                if (reported[i][toI]) {
                    answer[i][0]++;
                }
            }
        }
    });
    
    console.log(answer);
    
    return answer.map(([a, b]) => a);
}