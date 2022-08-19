//枚举
var busyStudent = function (startTime, endTime, queryTime) {
    const n = startTime.length;
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            ans++;
        }
    }
    return ans;
};


//差分数组
var busyStudent = function (startTime, endTime, queryTime) {
    const n = startTime.length;
    const maxEndTime = _.max(endTime);
    if (queryTime > maxEndTime) {
        return 0;
    }
    const cnt = new Array(maxEndTime + 2).fill(0);
    for (let i = 0; i < n; i++) {
        cnt[startTime[i]]++;
        cnt[endTime[i] + 1]--;
    }
    let ans = 0;
    for (let i = 0; i <= queryTime; i++) {
        ans += cnt[i];
    }
    return ans;
};

