
function calcSalePrice(price, saleRatio) {
    return price - price * saleRatio / 100;
}

function solution(users, emoticons) {
    let answer = [0, 0];
    
    const N = users.length;
    const M = emoticons.length;
    const saleRatios = [10, 20, 30, 40];
    
    for (let i=0; i<Math.pow(4,M); i++) {
        const current = [0, 0];
        const currentUserBuy = Array(N).fill(0);
        let tmp = i;
        
        emoticons.forEach((price) => {
            const saleRatio = saleRatios[tmp % 4];
            tmp = Math.floor(tmp / 4);
            users.forEach(([비율, _], idx) => {
                if (비율 <= saleRatio) {
                    currentUserBuy[idx] += calcSalePrice(price, saleRatio);
                }
            });
        })
        currentUserBuy.forEach((userBuy, idx) => {
            if (users[idx][1] <= userBuy) {
                current[0] += 1;
            } else {
                current[1] += userBuy;
            }
        })
        if (current[0] < answer[0]) {
            continue;
        }
        if (answer[0] < current[0]) {
            answer = current;
            continue;
        }
        // answer[0] === current[0]
        answer[1] = Math.max(answer[1], current[1]);
    }
    
    return answer;
}