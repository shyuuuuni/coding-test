function split(timeline) {
    const [date, endtime, duration] =  timeline.split(" ");
    const durationMs = Number(duration.split("s")[0]),
          offset = 0.001;
    
    const seg = new Date(new Date(`${date} ${endtime}`).getTime() + offset*1000);
    
    const end = new Date(seg.getTime() - offset*1000),
          stt = new Date(seg.getTime() - durationMs*1000);
    
    return [stt.getTime(), end.getTime(), seg.getTime()];
}

function solution(lines) {
    let answer = 1;
    
    const map = new Map(),
          splitLines = lines.map(split);
    
    splitLines.forEach(([stt,end,seg]) => {
        map.set(stt, (map.get(stt) ?? 0) + 1);
        map.set(seg, (map.get(seg) ?? 0) - 1);
    });
    splitLines.sort((a,b) => {
        return a[0]-b[0];
    });
    
    for (let i=0; i<splitLines.length; i++) {
        const [curTime, maxTime] = splitLines[i];
        let count = 1; // 본인 포함
        // curTime기준 1초 탐색
        for (let j=0; j<splitLines.length; j++) {
            if (i === j) {
                continue;
            }
            
            const [nextTime, nextMaxTime] = splitLines[j];
            if (nextMaxTime < curTime || curTime + 1000 <= nextTime) {
                continue;
            }
            count++;
        }
        answer = Math.max(answer, count);
        
        count = 1;
        // maxTime기준 1초 탐색
        for (let j=i+1; j<splitLines.length; j++) {
            const [nextTime, nextMaxTime] = splitLines[j];
            if (maxTime + 1000 <= nextTime) {
                break;
            }
            if (nextTime <= maxTime && maxTime <= nextMaxTime) {
                count++;
                continue;
            }
            if (maxTime <= nextTime && nextTime < maxTime + 1000) {
                count++;
            }
        }
        answer = Math.max(answer, count);
    }
    
    return answer;
}