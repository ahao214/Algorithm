var singleNumber = function (nums) {
    const freq = new Map();
    for (const num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    let ans = 0;
    for (const [num, occ] of freq.entries()) {
        if (occ === 1) {
            ans = num;
            break;
        }
    }
    return ans;
};



var singleNumber = function (nums) {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        let total = 0;
        for (const num of nums) {
            total += ((num >> i) & 1);
        }
        if (total % 3 != 0) {
            ans |= (1 << i);
        }
    }
    return ans;
};


