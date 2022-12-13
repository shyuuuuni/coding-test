function solution(ingredient) {
    let answer = 0;
    let stack = [];
    ingredient.forEach((cur) => {
        const top = stack[stack.length-1];
        if (top?.onProgress && (top.value === 3 && cur === 1)) {
            answer++;
            stack.pop();
            stack.pop();
            stack.pop();
            return;
        }
        if (top?.onProgress && (cur - top.value === 1)) {
            stack.push({value: cur, onProgress: true});
            return;
        }
        if (cur === 1) {
            stack.push({value: cur, onProgress: true});
            return;
        }
        stack.push({value: cur, onProgress: false});
        return;
    });
    return answer;
}