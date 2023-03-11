/**
 * [0, 2, 11, 14, 21, 17, 25] 여기서 2개 지우기 (0, 25 제외)
 * [0, 2, 11, 14, 17, 21, 25]
 * 0 -> 11 -> 17 -> 21 -> 25 가 베스트
 * 여기서 화살표 === jump수 === total-n+1 (5-2+1 = 4)
 */
// 1. 만약 next permutation을 이용해 완탐? -> 50000C25000 -> 시간초과
// 2. 이분탐색 -> 어떤걸 이분탐색? 최소 거리를 기준으로?
//    그럼 n(몇개 지울지) 는 어디에 사용함?
//    최소 거리를 기준으로 jump -> jump수 === (전체 개수 - n)면?
//    최소값을 낮춰보기!!

function solution(distance, rocks, n) {
    const total = rocks.length;
    
    rocks.sort((a,b) => a-b);
    rocks.push(distance); // 도착점
    
    console.log(rocks);
    
    let le=0,
        ri=distance;
    let answer = distance;
    
    while (le < ri) {
        const mid = Math.floor((le+ri)/2); // 점프 최소 거리
        let jump = 0, cur = 0;
                
        rocks.forEach((rock) => {
            const dist = rock - cur;
            if (mid <= dist) {
                jump++;
                cur = rock;
            }
        });
        
        console.log(le, ri, mid, jump, total-n+1);
        
        
        if (total-n+1 > jump) {
            ri = mid;
        } else {
            le = mid + 1;
            answer = mid;
        }
    }
    
    return answer;
}