const INF = 0x3f3f3f3f;
var makeArrayIncreasing = function(arr1, arr2) {
    arr2.sort((a, b) => a - b);
    const list = [];
    let prev = -1;
    for (const num of arr2) {
        if (num !== prev) {
            list.push(num);
            prev = num;
        }
    }
    const n = arr1.length;
    const m = list.length;
    const dp = new Array(n + 1).fill(0).map(() => new Array(Math.min(m, n) + 1).fill(INF));
    dp[0][0] = -1;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= Math.min(i, m); j++) {
            /* 如果当前元素大于序列的最后一个元素 */
            if (arr1[i - 1] > dp[i - 1][j]) {
                dp[i][j] = arr1[i - 1];
            }
            if (j > 0 && dp[i - 1][j - 1] !== INF) {
                /* 查找严格大于 dp[i - 1][j - 1] 的最小元素 */
                const idx = binarySearch(list, j - 1, dp[i - 1][j - 1]);
                if (idx !== list.length) {
                    dp[i][j] = Math.min(dp[i][j], list[idx]);
                }
            }
            if (i === n && dp[i][j] !== INF) {
                return j;
            }
        }
    }
    return -1;
}

const binarySearch = (list, low, target) => {
    let high = list.length;
    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);
        if (list[mid] > target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
};


const INF = 0x3f3f3f3f;
var makeArrayIncreasing = function (arr1, arr2) {
    arr2.sort((a, b) => a - b);
    const list = [];
    let prev = -1;
    for (const num of arr2) {
        if (num !== prev) {
            list.push(num);
            prev = num;
        }
    }
    const temp = new Array(arr1.length + 2).fill(0);
    temp.splice(1, arr1.length, ...arr1);
    /* 右侧哨兵 inf */
    temp[arr1.length + 1] = INF;
    /* 左侧哨兵 -1 */
    temp[0] = -1;
    arr1 = temp;
    const n = arr1.length;
    const m = list.length;

    const dp = new Array(n).fill(INF);
    dp[0] = 0;
    for (let i = 1; i < n; i++) {
        /* arr1[i] 左侧的元素不进行替换 */
        if (arr1[i - 1] < arr1[i]) {
            dp[i] = Math.min(dp[i], dp[i - 1]);
        }
        /* 替换 arr1[i] 左边的连续 j 个元素 */
        for (let j = 1; j < i; j++) {
            /* arr2 的最优替换的起点为大于 arr1[i - j - 1] 的最小元素 */
            const k = binarySearch(list, arr1[i - j - 1]);
            /* arr2 的最优替换的终点必须满足小于 arr1[i] */
            if (k + j - 1 < m && list[k + j - 1] < arr1[i]) {
                dp[i] = Math.min(dp[i], dp[i - j - 1] + j);
            }
        }

    }
    return dp[n - 1] === INF ? -1 : dp[n - 1];
}

const binarySearch = (list, target) => {
    let low = 0, high = list.length;
    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);
        if (list[mid] > target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
};



const INF = 0x3f3f3f3f;
var makeArrayIncreasing = function (arr1, arr2) {
    arr2.sort((a, b) => a - b);
    const list = [];
    let prev = -1;
    for (const num of arr2) {
        if (num !== prev) {
            list.push(num);
            prev = num;
        }
    }
    const temp = new Array(arr1.length + 2).fill(0);
    temp.splice(1, arr1.length, ...arr1);
    /* 右侧哨兵 inf */
    temp[arr1.length + 1] = INF;
    /* 左侧哨兵 -1 */
    temp[0] = -1;
    arr1 = temp;
    const n = arr1.length;
    const m = list.length;

    const dp = new Array(n).fill(INF);
    dp[0] = 0;
    for (let i = 1; i < n; i++) {
        /* arr1[i] 左侧的元素不进行替换 */
        if (arr1[i - 1] < arr1[i]) {
            dp[i] = Math.min(dp[i], dp[i - 1]);
        }
        /* 固定替换元素的右侧终点 */
        const k = binarySearch(list, arr1[i]);
        /* 枚举从 i 左侧连续替换元素的个数 */
        for (let j = 1; j <= Math.min(i - 1, k); ++j) {
            /* 替换的连续 j 个元素的左侧起点需满足大于 arr1[i - j - 1] */
            if (arr1[i - j - 1] < list[k - j]) {
                dp[i] = Math.min(dp[i], dp[i - j - 1] + j);
            }
        }
    }
    return dp[n - 1] === INF ? -1 : dp[n - 1];
}

const binarySearch = (list, target) => {
    let low = 0, high = list.length;
    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);
        if (list[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
};
