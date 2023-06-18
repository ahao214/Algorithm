var maxSumDivThree = function (nums) {
    const v = [[], [], []];
    for (const num of nums) {
        v[num % 3].push(num);
    }
    v[1].sort((a, b) => b - a);
    v[2].sort((a, b) => b - a);

    let ans = 0;
    const lb = v[1].length;
    const lc = v[2].length;
    for (let cntb = lb - 2; cntb <= lb; ++cntb) {
        if (cntb >= 0) {
            for (let cntc = lc - 2; cntc <= lc; ++cntc) {
                if (cntc >= 0 && (cntb - cntc) % 3 === 0) {
                    ans = Math.max(ans, getSum(v[1], 0, cntb) + getSum(v[2], 0, cntc));
                }
            }
        }
    }
    return ans + getSum(v[0], 0, v[0].length);
}

const getSum = (list, start, end) => {
    let sum = 0;
    for (let i = start; i < end; ++i) {
        sum += list[i];
    }
    return sum;
};



var maxSumDivThree = function (nums) {
    const v = [[], [], []];
    for (const num of nums) {
        v[num % 3].push(num);
    }
    v[1].sort((a, b) => b - a);
    v[2].sort((a, b) => b - a);

    const tot = nums.reduce((sum, num) => sum + num, 0);
    let remove = Infinity;

    if (tot % 3 === 0) {
        remove = 0;
    } else if (tot % 3 === 1) {
        if (v[1].length >= 1) {
            remove = Math.min(remove, v[1][v[1].length - 1]);
        }
        if (v[2].length >= 2) {
            remove = Math.min(remove, v[2][v[2].length - 2] + v[2][v[2].length - 1]);
        }
    } else {
        if (v[1].length >= 2) {
            remove = Math.min(remove, v[1][v[1].length - 2] + v[1][v[1].length - 1]);
        }
        if (v[2].length >= 1) {
            remove = Math.min(remove, v[2][v[2].length - 1]);
        }
    }

    return tot - remove;
}


var maxSumDivThree = function (nums) {
    let f = [0, Number.MIN_SAFE_INTEGER, Number.MIN_SAFE_INTEGER];
    for (const num of nums) {
        const g = [...f];
        for (let i = 0; i < 3; ++i) {
            g[(i + num % 3) % 3] = Math.max(g[(i + num % 3) % 3], f[i] + num);
        }
        f = g;
    }
    return f[0];
};