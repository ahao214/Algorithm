﻿var countMatches = function (items, ruleKey, ruleValue) {
    const index = { "type": 0, "color": 1, "name": 2 }[ruleKey];
    let res = 0;
    for (const item of items) {
        if (item[index] === ruleValue) {
            res++;
        }
    }
    return res;
};
