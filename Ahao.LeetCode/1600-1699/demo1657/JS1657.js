﻿var closeStrings = function (word1, word2) {
    let count1 = new Array(26).fill(0), count2 = new Array(26).fill(0);
    for (let i = 0; i < word1.length; i++) {
        count1[word1.charCodeAt(i) - 97]++;
    }
    for (let i = 0; i < word2.length; i++) {
        count2[word2.charCodeAt(i) - 97]++;
    }
    for (let i = 0; i < 26; i++) {
        if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0) {
            return false;
        }
    }
    count1.sort();
    count2.sort();
    return count1.toString() == count2.toString();
};
