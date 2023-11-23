function isPrime(x) {
    if (x <= 1) {
        return false;
    }
    if (x === 2) {
        return true;
    }
    for (let i=2; i*i<=x; i++) {
        if (x % i === 0) {
            return false;
        }
    }
    return true;
}

function solution(n, k) {
    let answer = 0;
    
    const kNumber = n.toString(k);
    const tokens = kNumber.split("0");
    
    tokens.forEach((token) => {
        const tokenNumber = Number(token);
        if (isPrime(tokenNumber)) {
            answer++;
        }
    })
    
    return answer;
}