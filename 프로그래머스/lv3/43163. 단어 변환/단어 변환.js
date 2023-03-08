function split(arr, condition) {
    const t = [];
    const f = [];
    
    arr.forEach((item) => {
        if (condition(item)) {
            t.push(item);
        } else {
            f.push(item);
        }
    });
    
    return [t, f];
}

function solution(begin, target, words) {
    let answer = 0;
    
    const N = words.length;
    const visited = new Map();
    words.forEach((word) => {
        visited.set(word, -1);
    });
    
    const queue = [];
    let rest = [...words];
    queue.push(begin);
    visited.set(begin, 0);
    
    while (0 < queue.length) {
        const current = queue.shift();
        const currentVisited = visited.get(current);
        
        if (current === target) {
            return visited.get(target);
        }
        
        const [t, f] = split(rest, (word) => {
            let diff = 0;
            [...word].forEach((w, index) => {
                if (w !== current[index]) {
                    diff++;
                }
            });
            return diff === 1;
        });
        
        t.forEach((next) => {
            if (visited.get(next) !== -1) {
                return;
            }
            visited.set(next, currentVisited+1);
            queue.push(next);
        });
        
        rest = f;
    }
    
    return 0;
}