﻿var splitNum = function (num) {
    const stnum = [...String(num)].map(Number).sort((a, b) => a - b);
    let num1 = 0, num2 = 0;
    stnum.forEach((val, i) => {
        i % 2 == 0 ? num1 = num1 * 10 + val : num2 = num2 * 10 + val;
    });
    return num1 + num2;
};
