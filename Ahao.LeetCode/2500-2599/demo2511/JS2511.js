var captureForts = function (forts) {
    let ans = 0, pre = -1;
    for (let i = 0; i < forts.length; i++) {
        if (forts[i] == 1 || forts[i] == -1) {
            if (pre >= 0 && forts[i] != forts[pre]) {
                ans = Math.max(ans, i - pre - 1);
            }
            pre = i;
        }
    }
    return ans;
};


var captureForts = function (forts) {
    let ans = 0;
    let pre = -1; // 表示不存在
    for (let i = 0; i < forts.length; i++) {
        if (forts[i]) {
            if (pre >= 0 && forts[i] !== forts[pre]) { // 一个是 1，另一个是 -1
                ans = Math.max(ans, i - pre - 1);
            }
            pre = i;
        }
    }
    return ans;
};
