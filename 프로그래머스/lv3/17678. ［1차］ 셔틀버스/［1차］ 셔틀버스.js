function solution(n, t, m, timetable) {
    let answer = "00:00";
    
    function fromTime(time) {
        return new Date(`2023-04-11T${time}:00`);
    }
    function nextTime(curTime) { // Date Obj
        return new Date(curTime.getTime() + 1000*60*t);
    }
    function showTime(time) {
        const hh = time.getHours() < 10 ? '0'+String(time.getHours()) : time.getHours(),
              mm = time.getMinutes() < 10 ? '0'+String(time.getMinutes()) : time.getMinutes();
        return `${hh}:${mm}`;
    }
    
    timetable.sort((a,b) => {
        a = fromTime(a).getTime();
        b = fromTime(b).getTime();
        
        return a-b;
    });
    
    let shuttle,
        count = 0,
        peopleIdx = 0;
    const people = [];
    
    do {
        // shuttle update
        if (!shuttle) {
            shuttle = fromTime("09:00");
        } else {
            shuttle = nextTime(shuttle);
        }
        count++;
        
        // people move
        let currentPeople = [];
        while (currentPeople.length < m && peopleIdx < timetable.length) {
            const top = timetable[0];
            if (fromTime(top).getTime() <= shuttle.getTime()) {
                currentPeople.push(timetable.shift());
            } else {
                break;
            }
        }
        people.push({ shuttleTime: showTime(shuttle), p: currentPeople });
    } while(count < n);
    
    for (let i=people.length-1; 0<=i; i--) {
        const { shuttleTime, p } = people[i];
        
        if (p.length < m) {
            return shuttleTime;
        }
        const max = p[p.length-1];
        const yourTime = new Date(fromTime(max).getTime() - 1000);
        
        return showTime(yourTime)
    }
    
    
    
    return answer;
}