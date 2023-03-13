function solution(clothes) {
    let answer = 1;
    
    const map = new Map();
    
    clothes.forEach(([name, type]) => {
        if (!map.has(type)) {
            map.set(type, []);
        }
        map.get(type).push(name);
    });
    
    const list = Array.from(map.values());
    list.forEach((x) => {
        answer *= x.length+1;
    });
    
    return answer - 1;
}