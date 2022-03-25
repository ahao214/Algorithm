var sumOfUnique = function (nums) {
    const cnt = new Map();
    for (const num of nums) {
        cnt.set(num, (cnt.get(num) || 0) + 1);
    }
    let ans = 0;
    for (const [num, c] of cnt.entries()) {
        if (c == 1) {
            ans += num;
        }
    }
    return ans;
};

var sumOfUnique = function (nums) {
    let ans = 0;
    const state = new Map();
    for (const num of nums) {
        if (!state.has(num)) {
            ans += num;
            state.set(num, 1);
        } else if (state.get(num) == 1) {
            ans -= num;
            state.set(num, 2);
        }
    }
    return ans;
};