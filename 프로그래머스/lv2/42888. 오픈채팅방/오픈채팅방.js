const TYPE = {
    in: 0,
    out: 1,
};

function getMessage(type, id, mapper) {
    const nickname = mapper.get(id);
    
    switch (type) {
        case TYPE.in:
            return `${nickname}님이 들어왔습니다.`;
        case TYPE.out:
            return `${nickname}님이 나갔습니다.`
    }
    
    return null;
}

function solution(record) {
    const answer = [],
          map = new Map();
    
    record.map((rec) => {
        return rec.split(' ');
    }).forEach(([type, id, name]) => {
        if (type === 'Enter') {
            map.set(id, name);
            answer.push({ type: TYPE.in, id });
        } else if (type === 'Leave') {
            answer.push({ type: TYPE.out, id });
        } else if (type === 'Change') {
            map.set(id, name);
        }
    });
    
    return answer.map(({ type, id }) => {
        return getMessage(type, id, map);
    });
}