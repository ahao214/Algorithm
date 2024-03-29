﻿var maxScoreWords = function (words, letters, score) {
    let n = words.length, res = 0;
    const count = new Array(26).fill(0);
    for (const c of letters) {
        count[c.charCodeAt() - 'a'.charCodeAt()]++;
    }
    for (let s = 1; s < (1 << n); s++) {
        const wordCount = new Array(26).fill(0); // 统计子集 s 所有单词的字母数目
        for (let k = 0; k < n; k++) {
            if ((s & (1 << k)) === 0) { // words[k] 不在子集 s 中
                continue;
            }
            for (let i = 0; i < words[k].length; i++) {
                const c = words[k][i];
                wordCount[c.charCodeAt() - 'a'.charCodeAt()]++;
            }
        }
        let ok = true; // 判断子集 s 是否合法
        let sum = 0; // 保存子集 s 的得分
        for (let i = 0; i < 26; i++) {
            sum += score[i] * wordCount[i];
            ok = ok && (wordCount[i] <= count[i]);
        }
        if (ok) {
            res = Math.max(res, sum);
        }
    }
    return res;
};