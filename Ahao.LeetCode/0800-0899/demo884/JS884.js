﻿var uncommonFromSentences = function (s1, s2) {
    let freq = new Map();
    freq = insert(s1, freq);
    freq = insert(s2, freq);

    const ans = [];
    for (const entry of freq.entries()) {
        if (entry[1] === 1) {
            ans.push(entry[0]);
        }
    }
    return ans;
};

const insert = (s, freq) => {
    const arr = s.split(" ");
    for (const word of arr) {
        freq.set(word, (freq.get(word) || 0) + 1);
    }
    return freq;
};