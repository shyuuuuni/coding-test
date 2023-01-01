function solution(elements) {
    const N = elements.length;
    const checked = new Set();
    
    // seqs[i] : i번째 원소로부터 시작했을 때 수열
    const seqs = Array(N);

    // 배열 초기화
    for (let i=0; i<N; i++) {
        const arr = [...elements];
        const pop = arr.splice(0, i);
        arr.push(...pop);
        seqs[i] = arr;
    }
    
    // 부분 수열 합 계산
    for (let i=0; i<N; i++) {
        let acc = 0;
        seqs[i].forEach((item) => {
            acc += item;
            checked.add(acc);
        })
    }
    
    return checked.size;
}