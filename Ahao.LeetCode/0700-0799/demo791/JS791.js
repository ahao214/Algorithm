//自定义排序
var customSortString = function (order, s) {
    const val = new Array(26).fill(0);
    for (let i = 0; i < order.length; ++i) {
        val[order[i].charCodeAt() - 'a'.charCodeAt()] = i + 1;
    }
    const arr = new Array(s.length).fill(0).map((_, i) => s[i]);
    arr.sort((c0, c1) => val[c0.charCodeAt() - 'a'.charCodeAt()] - val[c1.charCodeAt() - 'a'.charCodeAt()])
    let ans = '';
    for (let i = 0; i < s.length; ++i) {
        ans += arr[i];
    }
    return ans;
};


//计数排序
var customSortString = function (order, s) {
    const freq = new Array(26).fill(0);
    for (let i = 0; i < s.length; ++i) {
        const ch = s[i];
        ++freq[ch.charCodeAt() - 'a'.charCodeAt()];
    }
    let ans = '';
    for (let i = 0; i < order.length; ++i) {
        const ch = order[i];
        while (freq[ch.charCodeAt() - 'a'.charCodeAt()] > 0) {
            ans += ch;
            freq[ch.charCodeAt() - 'a'.charCodeAt()]--;
        }
    }
    for (let i = 0; i < 26; ++i) {
        while (freq[i] > 0) {
            ans += String.fromCharCode(i + 'a'.charCodeAt());
            freq[i]--;
        }
    }
    return ans;
};
