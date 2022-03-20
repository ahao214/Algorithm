﻿var convertToBase7 = function (num) {
    if (num === 0) {
        return "0";
    }
    let negative = num < 0;
    num = Math.abs(num);
    const digits = [];
    while (num > 0) {
        digits.push(num % 7);
        num = Math.floor(num / 7);
    }
    if (negative) {
        digits.push('-');
    }
    return digits.reverse().join('');
};