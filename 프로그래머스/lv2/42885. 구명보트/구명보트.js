/**
 * Greedy: 보트가 2명까지 가능하므로, 작은사람+나머지 중 가장 큰사람이 가장 효율적일 것.
 * 왜냐하면 ex) 100을 20+80으로 채우기 vs 20+70으로 채우기
 * -> 만약 80을 안한다고 하면? 80자리는 70이 채울 수 있지만, 반대는 불가능.
 */
function solution(people, limit) {
    let answer = 0;
    
    const half = Math.floor(limit / 2); // 5kg -> 2+2 가능
    const small = people.filter((x) => x <= half).sort((a,b) => a-b);
    const big = people.filter((x) => half < x).sort((a,b) => b-a);
    
    let i=0, j=0;
    const smallR = [...small];
    const bigR = [...big];
    
    while (i < small.length && j < big.length) {
        if (limit < small[i] + big[j]) {
            j++
            continue;
        }
        
        smallR.shift();
        bigR.shift();
        i++;
        j++;
        answer++;
    }
    
    answer += Math.ceil(smallR.length/2);
    answer += bigR.length;
    
    return answer;
}