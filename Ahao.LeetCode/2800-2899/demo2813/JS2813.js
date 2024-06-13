﻿var findMaximumElegance = function (items, k) {
    items.sort((item0, item1) => item1[0] - item0[0])
    let categorySet = new Set();
    let profit = 0, res = 0;
    let st = [];
    for (let i = 0; i < items.length; i++) {
        if (i < k) {
            profit += items[i][0];
            if (!categorySet.has(items[i][1])) {
                categorySet.add(items[i][1]);
            } else {
                st.push(items[i][0]);
            }
        } else if (st.length > 0 && !categorySet.has(items[i][1])) {
            profit += items[i][0] - st.pop();
            categorySet.add(items[i][1]);
        }
        res = Math.max(res, profit + categorySet.size * categorySet.size);
    }
    return res;
};
