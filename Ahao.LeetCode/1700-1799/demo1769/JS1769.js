﻿var minOperations = function(boxes) {
    const n = boxes.length;
    const res = [];
    for (let i = 0; i < n; i++) {
        let sm = 0;
        for (let j = 0; j < n; j++) {
            if (boxes[j] === '1') {
                sm += Math.abs(j - i);
            }
        }
        res.push(sm);
    }
    return res;
};
