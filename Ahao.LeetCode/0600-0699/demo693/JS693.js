var hasAlternatingBits = function (n) {
    let prev = 2;
    while (n !== 0) {
        const cur = n % 2;
        if (cur === prev) {
            return false;
        }
        prev = cur;
        n = Math.floor(n / 2);
    }
    return true;
};


var hasAlternatingBits2 = function (n) {
    const a = n ^ (n >> 1);
    return (a & (a + 1)) == 0;
};