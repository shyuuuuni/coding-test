function solution(n, computers) {
    const parent = Array.from({ length: n }, (_, i) => i);
    
    const getParent = (x) => {
        if (x === parent[x]) {
            return x;
        }
        parent[x] = getParent(parent[x]);
        return parent[x];
    };
    
    const mergeUnion = (x, y) => {
        x = getParent(x);
        y = getParent(y);
        
        if (x < y) {
            return parent[y] = x;
        }
        parent[x] = y;
    };
    
    const isUnion = (x, y) => {
        return getParent(x) === getParent(y);
    }
    
    computers.forEach((destinations, stt) => {
        destinations.forEach((isCon, dst) => {
            if (stt !== dst && isCon === 1 && !isUnion(stt, dst)) {
                mergeUnion(stt, dst);
            }
        });
    });
    
    parent.forEach((p, i) => {
        parent[i] = getParent(i);
    })
    
    const set = new Set(parent);
    
    return set.size;
}