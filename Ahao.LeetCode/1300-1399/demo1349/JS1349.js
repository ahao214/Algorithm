﻿var maxStudents = function (seats) {
    const m = seats.length, n = seats[0].length;
    const memo = new Map();

    const isSingleRowCompliant = function (status, row) {
        for (let j = 0; j < n; j++) {
            if ((status >> j) & 1) {
                if (seats[row][j] == '#') {
                    return false;
                }
                if (j > 0 && ((status >> (j - 1)) & 1)) {
                    return false;
                }
            }
        }
        return true;
    };

    const isCrossRowsCompliant = function (status, upperRowStatus) {
        for (let j = 0; j < n; j++) {
            if ((status >> j) & 1) {
                if (j > 0 && ((upperRowStatus >> (j - 1)) & 1)) {
                    return false;
                }
                if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1)) {
                    return false;
                }
            }
        }
        return true;
    };

    const dp = function (row, status) {
        const key = (row << n) + status;
        if (!memo.has(key)) {
            if (!isSingleRowCompliant(status, row)) {
                memo.set(key, -Infinity);
                return -Infinity;
            }
            let students = bitCount(status);
            if (row == 0) {
                memo.set(key, students);
                return students;
            }
            let mx = 0;
            for (let upperRowStatus = 0; upperRowStatus < 1 << n; upperRowStatus++) {
                if (isCrossRowsCompliant(status, upperRowStatus)) {
                    mx = Math.max(mx, dp(row - 1, upperRowStatus));
                }
            }
            memo.set(key, students + mx);
        }
        return memo.get(key);
    };

    let mx = 0;
    for (let i = 0; i < (1 << n); i++) {
        mx = Math.max(mx, dp(m - 1, i));
    }
    return mx;
};

var bitCount = function (num) {
    let bits = num;
    bits = bits - ((bits >> 1) & 0x55555555);
    bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
    bits = (bits + (bits >> 4)) & 0x0f0f0f0f;
    bits = (bits + (bits >> 8)) & 0x00ff00ff;
    bits = (bits + (bits >> 16)) & 0x0000ffff;
    return bits;
}
