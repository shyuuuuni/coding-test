function solution(A, B) {
    let answer = 0;
    
    const sortedA = A.sort((a,b) => (a-b)),
          sortedB = B.sort((a,b) => (a-b));
    
    let ptrA = 0,
        ptrB = 0;
    
    while (ptrA < sortedA.length && ptrB < sortedB.length) {
        if (sortedA[ptrA] < sortedB[ptrB]) {
            answer++;
            ptrA++;
            ptrB++;
        } else {
            ptrB++;
        }
    }
    
    return answer;
}