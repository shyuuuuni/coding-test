const 종류_누적합_구하기 = (arr) => {
    const checked = Array(10000+1).fill(false);
    const 누적합 = [];
    
    for (let i=0; i<arr.length; i++) {
        const prev = 누적합[i-1] ?? 0;
        const topping = arr[i];
        
        if (checked[topping]) {
            누적합[i] = prev;
            continue;
        }
        checked[topping] = true;
        누적합[i] = prev + 1;
    }
    
    return 누적합;
}

function solution(toppings) {
    let answer = 0;
    
    const 왼쪽_누적합 = 종류_누적합_구하기(toppings);
    const 오른쪽_누적합 = 종류_누적합_구하기([...toppings].reverse()).reverse();
    
    // i: i번째 토핑 오른쪽을 자르는 경우
    for (let i=0; i<toppings.length-1; i++) {
        const left = 왼쪽_누적합[i];
        const right = 오른쪽_누적합[i+1];
        
        answer += (left===right) ? 1 : 0;
    }
    
    return answer;
}