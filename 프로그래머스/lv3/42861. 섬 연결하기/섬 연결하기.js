function solution(n, costs) {
    let answer = 0;
    
    const parent = Array.from(Array(n), (_,i) => i);
    
    function getParent(x) {
        if (parent[x] === x) {
            return x;
        }
        return parent[x] = getParent(parent[x]);
    }
    function union(x, y) {
        x = getParent(x);
        y = getParent(y);
        if (y < x) {
            parent[x]
        }
        parent[y] = x;
    }
    function isUnion(x, y) {
        return getParent(x) === getParent(y);
    }
    
    costs.sort((a,b) => a[2]-b[2]); // 가중치 기준 오름차순
    
    console.log(costs);
    
    costs.forEach(([stt,end,dist]) => {
        if (isUnion(stt,end)) {
            return;
        }
        union(stt, end);
        answer += dist;
    })
    
    return answer;
}