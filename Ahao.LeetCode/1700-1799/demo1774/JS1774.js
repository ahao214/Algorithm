﻿var closestCost = function (baseCosts, toppingCosts, target) {
    let res = _.min(baseCosts);
    const dfs = (toppingCosts, p, curCost, target) => {
        if (Math.abs(res - target) < curCost - target) {
            return;
        } else if (Math.abs(res - target) >= Math.abs(curCost - target)) {
            if (Math.abs(res - target) > Math.abs(curCost - target)) {
                res = curCost;
            } else {
                res = Math.min(res, curCost);
            }
        }
        if (p === toppingCosts.length) {
            return;
        }
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], target);
        dfs(toppingCosts, p + 1, curCost, target);
    };
    for (const b of baseCosts) {
        dfs(toppingCosts, 0, b, target);
    }
    return res;
}


var closestCost = function (baseCosts, toppingCosts, target) {
    const x = _.min(baseCosts);
    if (x >= target) {
        return x;
    }
    const can = new Array(target + 1).fill(0);
    let res = 2 * target - x;
    for (const b of baseCosts) {
        if (b <= target) {
            can[b] = true;
        } else {
            res = Math.min(res, b);
        }
    }
    for (const t of toppingCosts) {
        for (let count = 0; count < 2; ++count) {
            for (let i = target; i > 0; --i) {
                if (can[i] && i + t > target) {
                    res = Math.min(res, i + t);
                }
                if (i - t > 0) {
                    can[i] = can[i] | can[i - t];
                }
            }
        }
    }
    for (let i = 0; i <= res - target; ++i) {
        if (can[target - i]) {
            return target - i;
        }
    }
    return res;
}
