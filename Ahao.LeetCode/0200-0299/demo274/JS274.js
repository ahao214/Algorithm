var hIndex = function (citations) {
    citations.sort((a, b) => a - b);
    let h = 0, i = citations.length - 1;
    while (i >= 0 && citations[i] > h) {
        h++;
        i--;
    }
    return h;
};



var hIndex = function (citations) {
    let n = citations.length, tot = 0;
    const counter = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        if (citations[i] >= n) {
            counter[n]++;
        } else {
            counter[citations[i]]++;
        }
    }
    for (let i = n; i >= 0; i--) {
        tot += counter[i];
        if (tot >= i) {
            return i;
        }
    }
    return 0;
};



/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function (citations) {
    let left = 0, right = citations.length
    while (left < right) {
        // +1 防止死循环
        let mid = Math.floor((left + right + 1) / 2)
        let cnt = 0
        for (let v of citations) {
            if (v >= mid) {
                cnt += 1
            }
        }
        if (cnt >= mid) {
            // 要找的答案在 [mid,right] 区间内
            left = mid
        } else {
            // 要找的答案在 [0,mid) 区间内
            right = mid - 1
        }
    }
    return left
};
