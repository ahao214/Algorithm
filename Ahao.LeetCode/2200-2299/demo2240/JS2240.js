﻿var waysToBuyPensPencils = function (total, cost1, cost2) {
    if (cost1 < cost2) {
        return waysToBuyPensPencils(total, cost2, cost1);
    }
    let res = 0, cnt = 0;
    while (cnt * cost1 <= total) {
        res += parseInt((total - cnt * cost1) / cost2) + 1;
        cnt++;
    }
    return res;
};
