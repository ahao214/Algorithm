﻿var isCircularSentence = function (sentence) {
    const n = sentence.length;
    if (sentence[n - 1] !== sentence[0]) {
        return false;
    }
    for (let i = 0; i < n; i++) {
        if (sentence[i] === ' ' && sentence[i + 1] !== sentence[i - 1]) {
            return false;
        }
    }
    return true;
};
