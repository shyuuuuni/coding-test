function isAlphabet(c) {
    return /^[a-zA-Z]+$/.test(c);
}

function preprocessString(str) {
    const set = [],
          offset = 2;
    
    for (let i=0; i<str.length-1; i++) {
        set.push(str.slice(i, i+offset));
    }
    
    return set.filter((s) => {
        const c1 = s[0],
              c2 = s[1];
        return isAlphabet(c1) && isAlphabet(c2);
    }).map((c) => c.toUpperCase());
}

function getIntersect(set1, set2) {
    const map1 = new Map(),
          map2 = new Map();
    
    set1.forEach((c) => {
        map1.set(c, (map1.get(c) ?? 0) + 1);
    });
    set2.forEach((c) => {
        map2.set(c, (map2.get(c) ?? 0) + 1);
    });
    
    const intersectMap = new Map();
    for (const [c, count] of map1) {
        if (!map2.has(c)) {
            continue;
        }
        intersectMap.set(c, Math.min(count, map2.get(c)));
    }
    
    return intersectMap;
}

function getUnion(set1, set2) {
    const map1 = new Map(),
          map2 = new Map();
    
    set1.forEach((c) => {
        map1.set(c, (map1.get(c) ?? 0) + 1);
    });
    set2.forEach((c) => {
        map2.set(c, (map2.get(c) ?? 0) + 1);
    });
    
    const unionMap = new Map();
    for (const [c, count] of map1) {
        if (unionMap.has(c)) {
            continue;
        }
        unionMap.set(c, Math.max(count, map2.get(c) ?? 0));
    }
    for (const [c, count] of map2) {
        if (unionMap.has(c)) {
            continue;
        }
        unionMap.set(c, Math.max(count, map1.get(c) ?? 0));
    }
    
    return unionMap;
}

function solution(str1, str2) {
    const set1 = preprocessString(str1),
          set2 = preprocessString(str2);
    
    const intersect = getIntersect(set1, set2),
          union = getUnion(set1, set2);
    
    const i = [...intersect].reduce((acc,[key,value]) => {
        return acc + value;
    }, 0),
          u = [...union].reduce((acc,[key,value]) => {
        return acc + value;
    }, 0);
    
    if (i === u) {
        return 65536
    }
    
    return Math.floor(65536 * i / u);
}