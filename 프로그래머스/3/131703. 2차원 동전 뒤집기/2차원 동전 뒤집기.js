function solution(beginning, target) {
    let answer = Infinity;
    
    const N = beginning.length,
          M = beginning[0].length;
    
    function copy(board) {
        const _board = Array.from({ length: N }, (_, i) => [...board[i]]);
        
        return _board;
    }
    function reverseRow(board, row) {
        for (let i=0; i<M; i++) {
            board[row][i] = board[row][i] === 0 ? 1 : 0;
        }
    }
    function reverseColumn(board, col) {
        for (let i=0; i<N; i++) {
            board[i][col] = board[i][col] === 0 ? 1 : 0;
        }
    }
    function isSame(board) {
        let result = true;
        
        for(let i=0; i<N; i++) {
            for (let j=0; j<M && result; j++) {
                result = board[i][j] === target[i][j];
            }
        }
        
        return result;
    }
    function simulate(rowState, colState) {
        let cur = 0;
        const board = copy(beginning);
        
        for (let i=0, k=rowState; i<N; i++) {
            const change = (k & 1) === 1;
            if (change) {
                cur++;
                reverseRow(board, i);
            }
            k = (k >> 1);
        }
        for (let i=0, k=colState; i<M; i++) {
            const change = (k & 1) === 1;
            if (change) {
                cur++;
                reverseColumn(board, i);
            }
            k = (k >> 1);
        }
        
        if (cur >= answer) {
            return;
        }
        if (isSame(board)) {
            answer = cur;
        }
    }
    
    for (let i=0; i<(1<<N); i++) {
        for (let j=0; j<(1<<M); j++) {
            simulate(i, j);
        }
    }
    
    return answer === Infinity ? -1 : answer;
}