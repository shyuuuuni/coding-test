function solution(s) {
    const answer = [];
    const recentlyFindIndex = {};
    [...s].reduce((acc, cur, idx) => {
        if (recentlyFindIndex[cur] !== undefined) {
            acc.push(idx - recentlyFindIndex[cur]);
        } else {
            acc.push(-1);
        }
        recentlyFindIndex[cur] = idx;
        return acc;
    }, answer);
    return answer;
}