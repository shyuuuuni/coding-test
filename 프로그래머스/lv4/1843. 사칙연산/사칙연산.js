function solution(arr) {
    const N = (arr.length + 1) / 2; // [1, 3, 5, 8]
    // dp[i][j][j]: 숫자의 인덱스 i~j 를 사용한 경우 최대(0), 최소(1) 값 저장
    const dp = Array.from(Array(N), () => Array.from(Array(N), () => [-Infinity, Infinity]));
    
    const nums = arr.filter((num, idx) => idx % 2 === 0).map(Number);
    const signs = [1, ...arr.filter((num, idx) => idx % 2 === 1).map((sign) =>{
        if (sign === "-") {
            return -1;
        } else {
            return 1;
        }
    })];
    
    console.log(nums, signs);
                          
    // 메모 단계
    for (let offset=0; offset<N; offset++) {
        for (let i=0; i+offset<N; i++) {
            const j = i+offset;
            const target = dp[i][j];
            
            // 초기화 단계
            if (offset === 0) {
                target[0] = nums[i];
                target[1] = nums[i];
                continue;
            }
            
            // 메모 단계
            for (let k=0; k<offset; k++) {
                const left = dp[i][i+k];
                const right = dp[i+k+1][j];
                const sign = signs[i+k+1];

                [...left].forEach((lv) => {
                    [...right].forEach((rv) => {
                        const val = lv + sign * rv;
                        if (target[0] < val) {
                            target[0] = val;
                        }
                        if (val < target[1]) {
                            target[1] = val;
                        }
                    })
                });
            }
        }
    }
    
    return dp[0][N-1][0];
}