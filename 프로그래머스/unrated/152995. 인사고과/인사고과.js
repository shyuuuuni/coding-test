"use strict";

function solution(scores) {
    const 완호 = scores[0];
    const 근태점수_정렬결과 = [...scores].sort((a,b) => {
        if (a[0] === b[0]) {
            return a[1] - b[1];
        }
        return b[0] - a[0];
    });
    
    let topScore = 근태점수_정렬결과[0];
    let answer = 0;
    const 인센티브 = 근태점수_정렬결과.filter((score) => {
        const [최대근태, 최대동료] = topScore;
        const [근태, 동료] = score;
        
        /* 인센티브 X */
        if (근태 < 최대근태 && 동료 < 최대동료 && 완호 === score) {
            answer = -1;
            return false;
        }
        if (근태 < 최대근태 && 동료 < 최대동료) {
            return false;
        }
        /* 인센티브 O */
        if (최대동료 < 동료) {
            topScore = score;
        }
        return true;
    });
    
    if (answer === -1) {
        return -1;
    }
    
    
    return 인센티브.map(([근태, 동료]) => 근태+동료).sort((a,b) => b-a).findIndex((score) => score === 완호[0]+완호[1]) + 1;
}