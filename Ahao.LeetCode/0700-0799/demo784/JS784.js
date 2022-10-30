//方法一：广度优先搜索
var letterCasePermutation = function (s) {
    const ans = [];
    const q = [""];
    while (q.length !== 0) {
        let cur = q[0];
        const pos = cur.length;
        if (pos === s.length) {
            ans.push(cur);
            q.shift();
        } else {
            if (isLetter(s[pos])) {
                q.push(cur + swapCase(s[pos]));
            }
            q[0] += s[pos];
        }
    }
    return ans;
};

const swapCase = (ch) => {
    if ('a' <= ch && ch <= 'z') {
        return ch.toUpperCase();
    }
    if ('A' <= ch && ch <= 'Z') {
        return ch.toLowerCase();
    }
}

const isLetter = (ch) => {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}


//方法二：回溯
var letterCasePermutation = function (s) {
    const ans = [];
    const dfs = (arr, pos, res) => {
        while (pos < arr.length && isDigit(arr[pos])) {
            pos++;
        }
        if (pos === arr.length) {
            res.push(arr.join(""));
            return;
        }
        arr[pos] = String.fromCharCode(arr[pos].charCodeAt() ^ 32);
        dfs(arr, pos + 1, res);
        arr[pos] = String.fromCharCode(arr[pos].charCodeAt() ^ 32);
        dfs(arr, pos + 1, res);
    }
    dfs([...s], 0, ans);
    return ans;
};

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}

//方法三：二进制位图
var letterCasePermutation = function (s) {
    const n = s.length;
    let m = 0;
    for (let i = 0; i < n; i++) {
        if (isLetter(s[i])) {
            m++;
        }
    }
    const ans = [];
    for (let mask = 0; mask < (1 << m); mask++) {
        let sb = '';
        for (let j = 0, k = 0; j < n; j++) {
            if (isLetter(s[j]) && (mask & (1 << k++)) !== 0) {
                sb += s[j].toUpperCase();
            } else {
                sb += s[j].toLowerCase();
            }
        }
        ans.push(sb);
    }
    return ans;
};

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}

const isLetter = (ch) => {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}

