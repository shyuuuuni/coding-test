class Stack {
    constructor() {
        this.stack = [];
    }
    push(value) {
        this.stack.push(value);
    }
    pop() {
        if (this.stack.length === 0) {
            return undefined;
        }
        const value = this.stack.pop();
        return value;
    }
    top() {
        if (this.stack.length === 0) {
            return undefined;
        }
        const value = this.stack[this.stack.length-1];
        return value;
    }
}


function solution(cap, n, deliveries, pickups) {
    let answer = 0;
    
    // 택배 상자 배달 목록
    const deliveryStack = new Stack();
    const pickupStack = new Stack();
    
    deliveries.forEach((v,i) => {
        0 < v && deliveryStack.push([v,i+1]);
    });
    pickups.forEach((v,i) => {
        0 < v && pickupStack.push([v,i+1]);
    });
        
    while (deliveryStack.stack.length || pickupStack.stack.length) {
        let truck = cap;
        
        let [, di] = deliveryStack.top() ?? [, 0];
        let [, pi] = pickupStack.top() ?? [, 0];
        const distance = Math.max(di, pi);
        answer += distance * 2;
        
        // 배달 과정 - 이후에 cap개의 택배를 실을 수 있다.
        while (truck && deliveryStack.stack.length) {
            const [dv, di] = deliveryStack.pop();
            if (truck < dv) {
                deliveryStack.push([dv - truck, di]);
                truck -= truck;
            } else {
                truck -= dv;
            }
        }
        // 수거 과정
        truck = 0;
        while (truck < cap && pickupStack.stack.length) {
            const [pv, pi] = pickupStack.pop();
            if (cap < truck + pv) {
                const dif = cap - truck;
                pickupStack.push([pv - dif, pi]);
                truck += dif;
            } else {
                truck += pv;
            }
        }
    }
    
    return answer;
}