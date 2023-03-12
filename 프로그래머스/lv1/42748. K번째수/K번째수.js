function solution(array, commands) {
    const answer = [];
    
    commands.forEach(([stt,end,idx]) => {
        const arr = array.slice(stt-1,end)
                         .sort((a,b) => a-b);
        answer.push(arr[idx-1]);
    })
    
    return answer;
}