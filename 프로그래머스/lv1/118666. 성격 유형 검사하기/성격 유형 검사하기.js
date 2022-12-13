const SCORE = {
    1: -3,
    2: -2,
    3: -1,
    4: 0,
    5: 1,
    6: 2,
    7: 3,
};

const CHARACTER = {
    RT: 0,
    TR: 0,
    CF: 1,
    FC: 1,
    JM: 2,
    MJ: 2,
    AN: 3,
    NA: 3,
};

function solution(survey, choices) {
    const scores = {
        0: 0,
        1: 0,
        2: 0,
        3: 0,
    }
    
    survey.forEach((s, index) => {
        const character = CHARACTER[s];
        const score = choices[index];
        const left = s[0];
        const right = s[1];
        
        if (left < right) {
            scores[character] += SCORE[score];
        } else {
            scores[character] -= SCORE[score];
        }
    })
    
    const answers = ["RT", "CF", "JM", "AN"];
    
    return answers.reduce((acc,cur,index) => {
        const score = scores[CHARACTER[cur]];
        if (score <= 0) {
            return acc + cur[0];
        } else {
            return acc + cur[1];
        }
    },"");
}