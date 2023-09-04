﻿var minNumber = function (nums1, nums2) {
    const same = () => {
        const s = new Set(nums1);
        let x = 10;
        for (const m of nums2) {
            if (s.has(m)) {
                x = Math.min(x, m);
            }
        }
        return x == 10 ? -1 : x;
    }
    const count = same();
    if (count != -1) {
        return count;
    }
    const x = Math.min(...nums1);
    const y = Math.min(...nums2);
    return Math.min(x * 10 + y, y * 10 + x);
};
