﻿var arrayStringsAreEqual = function (word1, word2) {
    return join(word1) === join(word2);
}

const join = (words) => {
    let ret = '';
    for (const s of words) {
        ret += s;
    }
    return ret;
};




var arrayStringsAreEqual = function (word1, word2) {
    let p1 = 0, p2 = 0, i = 0, j = 0;
    while (p1 < word1.length && p2 < word2.length) {
        if (word1[p1][i] !== word2[p2][j]) {
            return false;
        }
        i++;
        if (i === word1[p1].length) {
            p1++;
            i = 0;
        }
        j++;
        if (j === word2[p2].length) {
            p2++;
            j = 0;
        }
    }
    return p1 == word1.length && p2 == word2.length;
};
