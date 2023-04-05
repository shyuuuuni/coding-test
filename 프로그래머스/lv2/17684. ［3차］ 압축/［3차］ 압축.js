function solution(msg) {
    const answer = [],
          map = new Map();
    let index = 27;
    
    // init map
    const atoz = new Array(26).fill().map((_, i) => [i+1, String.fromCharCode(i + 65)]);
    atoz.forEach(([index, word]) => {
        map.set(word, index);
    })
    
    const words = msg.split("");
    let w = "", c = "";
    
    for (let i=0; i<words.length; i++) {
        const word = words[i]; // 현재글자
        if (i !== words.length-1) {
            c = words[i+1]; // 다음글자
        } else {
            c = "";
        }
        
        if (w === ""){
            w = w.concat(word); // 현재입력
        }
        const wc = w.concat(c); // w+c
        
        if (map.has(w) && map.has(wc)) {
            w = wc;
            continue;
        }
        if (map.has(w) && !map.has(wc)) {
            answer.push(map.get(w));
            map.set(wc, index++);
            w = '';
            continue;
        }
    }
    
    if (w) {
        answer.push(map.get(w));
    }
    
    return answer;
}