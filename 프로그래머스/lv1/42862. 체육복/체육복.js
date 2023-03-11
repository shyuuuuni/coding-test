function solution(n, lost, reserve) {
    const count = Array(n+1).fill(1);
    lost.forEach((i) => {
        count[i]--;
    });
    reserve.forEach((i) => {
        count[i]++;
    })
    lost.sort((a,b) => a-b);
    lost.forEach((i) => {
        if (count[i] === 1) {
            return;
        }
        if (0 < i-1 && count[i-1] === 2) {
            count[i]++;
            count[i-1]--;
            return;
        }
        if (i+1 <= n && count[i+1] === 2) {
            count[i]++;
            count[i+1]--;
            return;
        }
    });
    count.shift();
    return count.filter((x) => 0 < x).length;
}