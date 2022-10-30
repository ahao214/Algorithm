﻿//方法一：广度优先搜索
var letterCasePermutation = function (s) {
    const ans = [];
    const q = [""];
    while (q.length !== 0) {
        let cur = q[0];
        const pos = cur.length;
        if (pos === s.length) {
            ans.push(cur);
            q.shift();
        } else {
            if (isLetter(s[pos])) {
                q.push(cur + swapCase(s[pos]));
            }
            q[0] += s[pos];
        }
    }
    return ans;
};

const swapCase = (ch) => {
    if ('a' <= ch && ch <= 'z') {
        return ch.toUpperCase();
    }
    if ('A' <= ch && ch <= 'Z') {
        return ch.toLowerCase();
    }
}

const isLetter = (ch) => {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}
