function solution(s) {
    const answer = [];
    const checked = Array(100_000 + 1).fill(false);
    
    const subsets = s.match(/{[0-9,]+}/g).map((subset) => {
        const elems = subset.substring(1, subset.length-1);
        return elems.split(',').map(Number);
    });
    
    subsets.sort((a,b) => {
        return a.length - b.length;
    });
    
    subsets.forEach((subset) => {
        for (let i=0; i<subset.length; i++) {
            const elem = subset[i];
            if (!checked[elem]) {
                checked[elem] = true;
                answer.push(elem);
                break;
            }
        }
    });
    
    return answer;
}