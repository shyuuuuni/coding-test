function solution(numbers, target) {
    let answer = 0;
    let checker = 0;
    
    const N = numbers.length;
    const sign = Array(N).fill(1);
    
    function check() {
        const sum = numbers.reduce((acc, num, index) => {
            return acc + num * sign[index];
        }, 0);
        return sum === target;
    }
    
    function track(index) {
        if (N <= index) {
            if (check()) {
                answer++;
            }
            return;
        }
        sign[index] = 1;
        track(index+1);
        
        sign[index] = -1;
        track(index+1);
    }
    
    track(0);
    
    return answer;
}