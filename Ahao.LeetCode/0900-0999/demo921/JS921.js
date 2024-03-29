﻿var minAddToMakeValid = function (s) {
    let res = 0;
    let leftCount = 0;
    let length = s.length;
    for (let i = 0; i < length; i++) {
        const c = s[i];
        if (c == '(') {
            leftCount++;
        } else {
            if (leftCount > 0) {
                leftCount--;
            } else {
                res++;
            }
        }
    }
    res += leftCount;
    return res;
}