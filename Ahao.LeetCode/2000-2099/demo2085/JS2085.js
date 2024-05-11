﻿var countWords = function (words1, words2) {
    // 统计字符串出现频率
    const freq1 = new Map();
    const freq2 = new Map();
    for (const w of words1) {
        freq1.set(w, (freq1.get(w) || 0) + 1);
    }
    for (const w of words2) {
        freq2.set(w, (freq2.get(w) || 0) + 1);
    }

    // 遍历 words1 出现的字符串并检查个数
    let res = 0;
    for (const [w, cnt1] of freq1.entries()) {
        if (cnt1 === 1 && freq2.get(w) === 1) {
            res++;
        }
    }
    return res;
};
