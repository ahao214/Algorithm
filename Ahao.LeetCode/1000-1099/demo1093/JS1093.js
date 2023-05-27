﻿var sampleStats = function (count) {
    let n = count.length;
    let total = count.reduce((acc, cur) => acc + cur, 0);
    let mean = 0.0;
    let median = 0.0;
    let min_num = 256;
    let max_num = 0;
    let mode = 0;

    let left = parseInt((total + 1) / 2);
    let right = parseInt((total + 2) / 2);
    let cnt = 0;
    let maxfreq = 0;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += count[i] * i;
        if (count[i] > maxfreq) {
            maxfreq = count[i];
            mode = i;
        }
        if (count[i] > 0) {
            if (min_num == 256) {
                min_num = i;
            }
            max_num = i;
        }
        if (cnt < right && cnt + count[i] >= right) {
            median += i;
        }
        if (cnt < left && cnt + count[i] >= left) {
            median += i;
        }
        cnt += count[i];
    }
    mean = sum / total;
    median = median / 2.0;
    return [min_num, max_num, mean, median, mode];
}
