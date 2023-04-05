function solution(m, musicinfos) {
    let answer = '',
        length = 0;
    const MIN = 1000 * 60;
    
    function preprocess(str) {
        str = str.replaceAll('C#', '1');
        str = str.replaceAll('D#', '2');
        str = str.replaceAll('F#', '3');
        str = str.replaceAll('G#', '4');
        str = str.replaceAll('A#', '5');
        return str;
    }
    
    m = preprocess(m);
    
    musicinfos.map((musicinfo) => {
        return musicinfo.split(',');
    }).forEach(([start,end,name,melody]) => {
        melody = preprocess(melody);

        const s = new Date(`2023-04-05 ${start}:00`),
              e = new Date(`2023-04-05 ${end}:00`);
        const streamingTime = (e - s) / MIN;
        let has;
        
        if (streamingTime <= length) {
            return;
        }
        
        const repeatTime = Math.floor(streamingTime / melody.length) + 1;
        has = melody.repeat(repeatTime).slice(0, streamingTime).includes(m);
        if (has) {
            answer = name;
            length = streamingTime;
        }
    })
    
    if (answer === '') {
        return '(None)';
    }
    return answer;
}