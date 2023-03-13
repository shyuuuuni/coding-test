function solution(genres, plays) {
    const N = genres.length;
    const music = [];
    const map = new Map();
    
    for (let i=0; i<N; i++) {
        if (!map.has(genres[i])) {
            map.set(genres[i], {
                play: 0,
                list: []
            });
        }
        map.get(genres[i]).play += plays[i];
        map.get(genres[i]).list.push([plays[i], i]);
    }
    
    const sortedGenre = [...map.keys()].sort((a,b) => {
        const aplay = map.get(a).play;
        const bplay = map.get(b).play;
        
        return bplay - aplay; // 내림차순
    });
    
    const answer = sortedGenre.reduce((acc, genre) => {
        const top = map.get(genre).list.sort((a, b) => {
            return b[0] - a[0];
        }).map(([play,i]) => i).slice(0, 2);
        return [...acc, ...top];
    }, []);
    
    return answer;
}