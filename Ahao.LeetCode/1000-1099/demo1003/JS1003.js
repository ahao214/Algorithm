﻿var isValid = function (s) {
    const stk = [];
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        stk.push(c);
        if (stk.length >= 3 && stk.slice(stk.length - 3).join("") === "abc") {
            stk.splice(stk.length - 3, 3);
        }
    }
    return stk.length === 0;
};
