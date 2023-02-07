function solution(n, lighthouse) {
    let answer = 0;
    
    const on = Array.from({length:n+1}, () => false);
    const nodes = Array.from({length:n}, (_,i) => i+1);
    
    while(0 < lighthouse.length) {
        // 맵 초기화
        const connected = new Map();
        lighthouse.forEach(([a,b]) => {
            if (!connected.has(a)) {
                connected.set(a, []);
            }
            if (!connected.has(b)) {
                connected.set(b, []);
            }
            connected.get(a).push(b);
            connected.get(b).push(a);
        });

        // 노드 분류
        const leafNodes = nodes.filter((node) => {
            return connected.get(node)?.length === 1;
        });

        // 리프 노드에 연결된 노드 불 켜기
        leafNodes.forEach((node) => {
            const [target] = connected.get(node);
            if (on[target]) {
                return;
            }
            on[target] = true;
            if (connected.get(target).length === 1) {
                answer += 0.5;
            } else {
                answer += 1;
            }
        });
        
        // 처리한 리프 노드 제거
        lighthouse = lighthouse.filter(([a,b]) => {
            // 둘 중 하나라도 켜져있는 경우 다음 검색에서 제외
            return !(on[a] || on[b]);
        })
    }
    
    return answer;
}