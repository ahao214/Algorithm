//哈希表
var greatestLetter = function (s) {
    const ht = new Set();
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        ht.add(c);
    }
    for (let i = 25; i >= 0; i--) {
        if (ht.has(String.fromCharCode('a'.charCodeAt() + i)) && ht.has(String.fromCharCode('A'.charCodeAt() + i))) {
            return String.fromCharCode('A'.charCodeAt() + i);
        }
    }
    return "";
};


//位运算
var greatestLetter = function (s) {
    let lower = 0, upper = 0;
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if ('a' <= c && c <= 'z') {
            lower |= 1 << (c.charCodeAt() - 'a'.charCodeAt());
        } else {
            upper |= 1 << (c.charCodeAt() - 'A'.charCodeAt());
        }
    }
    for (let i = 25; i >= 0; i--) {
        if ((lower & upper & (1 << i)) !== 0) {
            return String.fromCharCode('A'.charCodeAt() + i);
        }
    }
    return "";
};
