// fees: 기본시간, 기본요금, 단위시간, 단위요금
function solution(fees, records) {
    const cars = new Map();
    const parks = new Map();
    
    function convertToMin(hm) {
        const [h, m] = hm.split(":").map(Number);
    
        return h*60 + m;
    }
    
    function calc(min) {
        if (min <= fees[0]) {
            return fees[1];
        }
        return fees[1] + Math.ceil((min - fees[0]) / fees[2]) * fees[3];
    }
    
    records.forEach((record) => {
        const [hm, car, type] = record.split(" ");
        const time = convertToMin(hm);
        
        if (!cars.has(car)) {
            cars.set(car, 0);
        }
        
        if (type === "IN") {
            parks.set(car, time);
            return;
        }
        const diff = time - parks.get(car);
        parks.delete(car);
        
        cars.set(car, cars.get(car) + diff);
    });
    
    if(parks.size > 0) {
        const p = Array.from(parks);
        p.forEach(([car, time]) => {
            const diff = convertToMin('23:59') - time;
            cars.set(car, cars.get(car) + diff);
        })
        
    }
    
    const price = Array.from(cars).sort((a, b) => {
        const x = Number(a[0]),
              y = Number(b[0]);
        
        return x-y;
    });
    const answer = price.map(([a, b]) => calc(Number(b)));
    
    
    return answer;
}