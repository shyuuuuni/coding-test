

function solution(info, edges) {
    var answer = 0;
    
    const N = info.length;
    
    const adj = Array.from({ length: N }, () => {
        return Array.from({ length: N }, () => {
            return false;
        })
    });
    edges.forEach(([from, to]) => {
        adj[from][to] = true;
        adj[to][from] = true;
    })
    
    const visited = Array.from({ length: N }, () => false);
    const connected = Array.from({ length: N }, () => false);
    
    let sheep = 0,
        wolf = 0;
    
    function go(index) {
        
        const isSheep = info[index] === 0;
        
        visited[index] = true;
        connected[index] = false;
        if (isSheep) {
            sheep++
        } else {
            wolf++;
        } 
        
        if (answer < sheep) {
            answer = sheep;
        }
        
        
        const list = [];
        for (let i=0; i<N; i++) {
            if (visited[i]) continue;
            if (adj[index][i]) {
                list.push(i);
                connected[i] = true;
            }
        }
        
        function logging() {
            const v = [];
            const c = [];
            
            for(let i=0; i<N; i++) {
                if (visited[i]) v.push(i);
                if (connected[i]) c.push(i);
            }
            
            console.log(index, sheep, wolf, v, c);
        }
        
        // logging();
        
        for (let i=0; i<N; i++) {
            if (visited[i] || !connected[i]) continue;
            if (info[i] === 0) {
                go(i);
                continue;
            }
            if (info[i] === 1 && sheep > wolf+1) {
                go(i);
                continue;
            }
        }
        
        visited[index] = false;
        connected[index] = true;
        if (isSheep) {
            sheep--;
        } else {
            wolf--;
        }
        list.forEach((l) => connected[l] = false);
            
        return;
    }
    
    go(0);
    
    return answer;
}