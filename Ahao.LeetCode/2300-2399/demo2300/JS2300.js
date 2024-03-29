﻿var successfulPairs = function (spells, potions, success) {
    function binarySearch(nums, lo, hi, target) {
        let res = hi + 1;
        while (lo <= hi) {
            const mid = lo + Math.floor((hi - lo) / 2);
            if (nums[mid] > target) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }

    potions.sort((a, b) => a - b);
    return spells.map((item) => {
        return potions.length - binarySearch(potions, 0, potions.length - 1, (success - 1) / item)
    })
};



var successfulPairs = function (spells, potions, success) {
    const res = new Array(spells.length).fill(0);
    const idx = new Array(spells.length).fill(0).map((_, i) => i);
    idx.sort((a, b) => spells[a] - spells[b]);
    potions.sort((a, b) => b - a);
    let j = 0;
    for (p of idx) {
        let v = spells[p];
        while (j < potions.length && potions[j] * v >= success) {
            j++;
        }
        res[p] = j;
    }
    return res;
};
