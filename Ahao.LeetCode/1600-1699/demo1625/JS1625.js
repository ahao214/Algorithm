var findLexSmallestString = function (s, a, b) {
    const n = s.length;
    const vis = new Array(n).fill(false);
    let res = s;
    // 将 s 延长一倍，方便截取轮转后的字符串 t
    s = s + s;
    for (let i = 0; !vis[i]; i = (i + b) % n) {
        vis[i] = true;
        for (let j = 0; j < 10; j++) {
            let kLimit = b % 2 === 0 ? 0 : 9;
            for (let k = 0; k <= kLimit; k++) {
                // 每次进行累加之前，重新截取 t
                const t = [...s.slice(i, i + n)];
                for (let p = 1; p < n; p += 2) {
                    t[p] = String.fromCharCode('0'.charCodeAt() + (t[p].charCodeAt() - '0'.charCodeAt() + j * a) % 10);
                }
                for (let p = 0; p < n; p += 2) {
                    t[p] = String.fromCharCode('0'.charCodeAt() + (t[p].charCodeAt() - '0'.charCodeAt() + k * a) % 10);
                }
                const tStr = t.join('');
                if (tStr < res) {
                    res = tStr;
                }
            }
        }
    }
    return res;
};
