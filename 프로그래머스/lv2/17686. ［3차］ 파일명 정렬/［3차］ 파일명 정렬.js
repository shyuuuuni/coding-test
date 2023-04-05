function solution(files) {
    const answer = [],
          regex = /([0-9]+)/i;
    
    const newFiles = files.map((fileName) => {
        const number = fileName.match(regex)[0];
        return fileName.split(new RegExp(`(${number})`)); // [head, number, tail];
    }).sort((a, b) => {
        const ha = a[0].toLowerCase(),
              hb = b[0].toLowerCase();
        if (ha !== hb) {
            return ha < hb ? -1 : 1;
        }
        const na = Number(a[1]),
              nb = Number(b[1]);
        if (na !== nb) {
            return na - nb;
        }
        return 1;
    });
    
    return newFiles.map((fileName) => fileName.join(''));
}