function solution(s){
    let answer = true;
    
    const stack = [];
    
    [...s].forEach((c) => {
        if (!answer) {
            return;
        }
        if (c === '(') {
            stack.push(c);
            return;
        }
        if (!stack.length) {
            answer = false;
            return;
        }
        if (stack[stack.length-1] === '(') {
            stack.pop();
            return;
        }
        answer = false;
    });
    
    answer = answer && stack.length === 0;

    return answer;
}