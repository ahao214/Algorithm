﻿//哈希表
var greatestLetter = function (s) {
    const ht = new Set();
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        ht.add(c);
    }
    for (let i = 25; i >= 0; i--) {
        if (ht.has(String.fromCharCode('a'.charCodeAt() + i)) && ht.has(String.fromCharCode('A'.charCodeAt() + i))) {
            return String.fromCharCode('A'.charCodeAt() + i);
        }
    }
    return "";
};


