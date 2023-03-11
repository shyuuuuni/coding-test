/**
 * Greedy: 앞 자리가 큰 숫자가 더 크다.
 * 즉, i < j 면서 n[i] < n[j] 면 i번째 원소를 지우는 것이 좋음.
 */
function solution(number, k) {
    const targetSize = number.length - k;
    const nums = [...number].map(Number);
    const stack = [];
    
    for (let i=0; i<nums.length; i++) {
        if (k <= 0) {
            stack.push(nums[i]);
            continue;
        }
        if (stack.length === 0) {
            stack.push(nums[i]);
            continue;
        }
        while (stack[stack.length-1] < nums[i]
              && 0 < k
              && stack.length) {
            stack.pop();
            k--;
        }
        stack.push(nums[i]);
    }
    
    while (0 < k) {
        stack.pop();
        k--;
    }
    
    return stack.join("");
}