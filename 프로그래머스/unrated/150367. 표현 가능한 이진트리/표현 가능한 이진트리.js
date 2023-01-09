function solution(numbers) {
    const toBinNumber = (number) => number.toString(2);
    const possiblePbt = (binNumber, one) => {
        const N = binNumber.length;
        const mid = Math.floor(N / 2);
        
        if (N === 1) {
            return one ? binNumber[mid] === '1' : binNumber[mid] === '0';
        }
        if (one) {
            const cur = binNumber[mid] === '1';
            const left = possiblePbt(binNumber.substring(0,mid), true) ||
                         possiblePbt(binNumber.substring(0,mid), false);
            const right = possiblePbt(binNumber.substring(mid+1), true) ||
                         possiblePbt(binNumber.substring(mid+1), false);
            return cur && left && right;
        }
        return binNumber[mid] === '0' &&
            possiblePbt(binNumber.substring(0,mid), false) &&
            possiblePbt(binNumber.substring(mid+1), false);
    };
    const check = (binNumber) => {
        const pbtSize = [1, 3, 7, 15, 31, 63]; // 10^15: 길이=50
        const N = binNumber.length;
        return pbtSize
            .filter((size) => N <= size)
            .map((size) => '0'.repeat(size-N) + binNumber)
            .filter((binNumber) => binNumber[Math.floor(binNumber.length/2)] === '1')
            .some((binNumber) => possiblePbt(binNumber, true));
    };
    
    const answer = numbers.map(toBinNumber)
                          .map(check)
                          .map((result) => result ? 1 : 0);
    
    return answer;
}