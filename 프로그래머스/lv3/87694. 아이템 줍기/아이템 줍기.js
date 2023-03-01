// 상수
const MAP_SIZE = 50;
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

const addRectangle = (map) => (rectangle) => {
    const [sttX, sttY, endX, endY] = rectangle.map((x) => x*2);
    
    for (let x=sttX; x<=endX; x++) {
        if (x === sttX || x === endX) {
            for (let y=sttY; y<=endY; y++) {
                map[y][x] = 1;
            }
            continue;
        }
        map[sttY][x] = 1;
        map[endY][x] = 1;
    }
}

const setBorder = (map) => (rectangle) => {
    const [sttX, sttY, endX, endY] = rectangle.map((x) => x*2);
    
    for (let x=sttX+1; x<endX; x++) {
        for (let y=sttY+1; y<endY; y++) {
            map[y][x] = 0;
        }
    }
}

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}
class Queue {
    constructor() {
        this.size = 0;
        this.first = null;
        this.last = null;
    }
    push(value) {
        const node = new Node(value);
        if (this.size === 0) {
            this.first = node;
            this.last = node;
        } else {
            this.last.next = node;
            this.last = node;
        }
        this.size++;
        
        return value;
    }
    pop() {
        if (this.size === 0) {
            return null;
        }
        const value = this.first.value;
        if (this.size === 1) {
            this.first = null;
            this.last = null;
        } else {
            this.first = this.first.next;
        }
        this.size--;
        
        return value;
    }
    empty() {
        return this.size === 0;
    }
}

function solution(rectangle, characterX, characterY, itemX, itemY) {
    const map = Array.from({length: MAP_SIZE*2 + 1}, () => Array.from({length: MAP_SIZE*2 + 1}).fill(0));
    
    // step1
    rectangle.forEach(addRectangle(map));
    rectangle.forEach(setBorder(map));
    
    const q = new Queue();
    const visit = Array.from({length: MAP_SIZE*2 + 1}, () => Array.from({length: MAP_SIZE*2 + 1}).fill(-1));
    q.push([characterX*2, characterY*2]);
    visit[characterY*2][characterX*2] = 0;
    
    while(!q.empty()) {
        const [x,y] = q.pop();
        const distance = visit[y][x];
        
        if (x === itemX*2 && y === itemY * 2) {
            return Math.floor(distance / 2);
        }
        
        for (let i=0; i<4; i++) {
            const [nx, ny] = [x + dx[i], y + dy[i]];
            
            if (nx < 0 || ny < 0 || MAP_SIZE*2 < nx || MAP_SIZE*2 < ny) {
                continue; // out of bound
            }
            if (visit[ny][nx] !== -1 || map[ny][nx] !== 1) {
                continue;
            }
            visit[ny][nx] = distance + 1;
            q.push([nx,ny]);
        }
    }
    
    
    return 0;
}