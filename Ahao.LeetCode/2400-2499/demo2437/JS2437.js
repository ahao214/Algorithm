﻿var countTime = function (time) {
    let res = 0;
    const dfs = (arr, pos) => {
        if (pos === arr.length) {
            if (check(arr)) {
                res++;
            }
            return;
        }
        if (arr[pos] === '?') {
            for (let i = 0; i <= 9; i++) {
                arr[pos] = String.fromCharCode('0'.charCodeAt() + i);
                dfs(arr, pos + 1);
                arr[pos] = '?';
            }
        } else {
            dfs(arr, pos + 1);
        }
    }

    const check = (arr) => {
        const hh = (arr[0].charCodeAt() - '0'.charCodeAt()) * 10 + arr[1].charCodeAt() - '0'.charCodeAt();
        const mm = (arr[3].charCodeAt() - '0'.charCodeAt()) * 10 + arr[4].charCodeAt() - '0'.charCodeAt();
        return hh < 24 && mm < 60;
    };
    const arr = [...time];
    dfs(arr, 0);
    return res;
}
