function solution(s) {
    const arr = s.split(" ").map(Number);
    console.log(arr);
    return `${Math.min(...arr)} ${Math.max(...arr)}`
}