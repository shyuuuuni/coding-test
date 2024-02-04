function solution(tickets) {
    const set = Array.from(new Set(tickets.flatMap((arr) => [...arr]))).sort();
    const map = new Map();
    
    const N = set.length;
    
    for (let i=0; i<set.length; i++) {
        map.set(set[i], i);
        map.set(i, set[i]);
    }
    
    for (let ticket of tickets) {
        ticket[0] = map.get(ticket[0]);
        ticket[1] = map.get(ticket[1]);
    }
        
    const adj = Array.from({ length: N }, () => {
        return [];
    });
    
    for (let i=0; i<tickets.length; i++) {
        const [from, to] = tickets[i];
        adj[from].push([to, true]); // [목적지, 티켓 유효성]
    }
    
    adj.forEach((a) => a.sort());
    
    const start = map.get('ICN');
    
    function go(current = start, count = 0, path = [start]) {
        if (count === tickets.length) {
            return path;
        }
        
        const nexts = adj[current];
        for (let i=0; i<nexts.length; i++) {
            let res;
            
            if (!nexts[i][1]) {
                continue;
            }
            
            // go
            nexts[i][1] = false;
            path.push(nexts[i][0]);
            count++;
            res = go(nexts[i][0], count, path);
            if (res.length > 0) {
                return res;
            }
            
            // back
            nexts[i][1] = true;
            path.pop();
            count--;
        }
        
        return [];
    }
    
    const results = go();
    
    return results.map((x) => map.get(x));
}