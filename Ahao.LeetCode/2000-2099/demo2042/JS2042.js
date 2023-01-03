﻿var areNumbersAscending = function (s) {
    let pre = 0, pos = 0;
    while (pos < s.length) {
        if (isDigit(s[pos])) {
            let cur = 0;
            while (pos < s.length && isDigit(s[pos])) {
                cur = cur * 10 + s[pos].charCodeAt() - '0'.charCodeAt();
                pos++;
            }
            if (cur <= pre) {
                return false;
            }
            pre = cur;
        } else {
            pos++;
        }
    }
    return true;
};

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}