﻿var numDifferentIntegers = function (word) {
    const set = new Set();
    let n = word.length, p1 = 0, p2;
    while (true) {
        while (p1 < n && !isDigit(word[p1])) {
            p1++;
        }
        if (p1 === n) {
            break;
        }
        p2 = p1;
        while (p2 < n && isDigit(word[p2])) {
            p2++;
        }
        while (p2 - p1 > 1 && word[p1] === '0') {
            p1++;
        }
        set.add(word.slice(p1, p2));
        p1 = p2;
    }
    return set.size;
};

const isDigit = (ch) => {
    return '0' <= ch && ch <= '9';
}
