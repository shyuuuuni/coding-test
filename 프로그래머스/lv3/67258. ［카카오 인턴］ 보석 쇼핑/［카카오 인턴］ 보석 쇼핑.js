function solution(gems) {
    const map = new Map(),
          countmap = new Map();
    
    gems.forEach((gem) => {
        if (!map.has(gem)) {
            map.set(gem, 0);
            countmap.set(gem, 0);
        }
        map.set(gem, map.get(gem) + 1);
    });
    
    const TOTAL = map.size,
          answer = [];
    let current = 0;
    
    let le = 0, ri = -1;
    while (le < gems.length && ri < gems.length) {
        if (current < TOTAL) {
            ri++;
            const rgem = gems[ri];
            const rcount = countmap.get(rgem);
            if (rcount === 0) {
                current++;
            }
            countmap.set(rgem, rcount+1);
            continue;
        }
        if (current === TOTAL) {
            if (answer.length === 0 || ri - le < answer[1] - answer[0]) {
                answer[1] = ri;
                answer[0] = le;
            }
            const lgem = gems[le];
            const lcount = countmap.get(lgem);
            if (lcount === 1) {
                current--;
            }
            countmap.set(lgem, lcount-1);
            le++;
            continue;
        }
    }
    
    return [answer[0]+1, answer[1]+1];
}