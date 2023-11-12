function solution(numbers, hand) {
    const answer = [];
    
    const left = [3, 0],
          right = [3, 2];
    
    const position = [
        [3, 1],
        [0, 0],
        [0, 1],
        [0, 2],
        [1, 0],
        [1, 1],
        [1, 2],
        [2, 0],
        [2, 1],
        [2, 2]
    ];
    
    function getDistance(a, b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
    
    numbers.forEach((number) => {
        if (number === 1 || number === 4 || number === 7) {
            left[0] = position[number][0];
            left[1] = position[number][1];
            answer.push('L');
            return;
        }
        if (number === 3 || number === 6 || number === 9) {
            right[0] = position[number][0];
            right[1] = position[number][1];
            answer.push('R');
            return;
        }
        
        const dLeft = getDistance(left, position[number]),
              dRight = getDistance(right, position[number]);
        
        if (dLeft === dRight && hand === 'right') {
            right[0] = position[number][0];
            right[1] = position[number][1];
            answer.push('R');
            return;
        }
        if (dLeft === dRight && hand === 'left') {
            left[0] = position[number][0];
            left[1] = position[number][1];
            answer.push('L');
            return;
        }
        if (dLeft < dRight) {
            left[0] = position[number][0];
            left[1] = position[number][1];
            answer.push('L');
            return;
        }
        if (dRight < dLeft) {
            right[0] = position[number][0];
            right[1] = position[number][1];
            answer.push('R');
            return;
        }
    })
    
    return answer.join('');
}