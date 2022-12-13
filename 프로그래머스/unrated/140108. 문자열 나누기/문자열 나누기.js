function solution(s) {
    let answer = 0;
    [...s].reduce(({ character, sameCount, otherCount }, cur, index)=>{
        if (index === s.length-1) {
            return;
        }
        if (character === undefined) {
            return { character: cur, sameCount: 1, otherCount: 0 };
        }
        if (character === cur) {
            return { character: cur, sameCount: sameCount+1, otherCount };
        }
        if (sameCount === otherCount+1) {
            answer++;
            return { character: undefined, sameCount: 0, otherCount: 0 };
        }
        return { character, sameCount, otherCount: otherCount+1 };
    }, {
        character: undefined,
        sameCount: 0,
        otherCount: 0
    });
    return 1 + answer;
}