﻿const ADDITION = -1;
const SUBTRACTION = -2;
const MULTIPLICATION = -3;

var diffWaysToCompute = function (expression) {
    const ops = [];
    for (let i = 0; i < expression.length;) {
        if (!isDigit(expression[i])) {
            if (expression[i] === '+') {
                ops.push(ADDITION);
            } else if (expression[i] === '-') {
                ops.push(SUBTRACTION);
            } else {
                ops.push(MULTIPLICATION);
            }
            i++;
        } else {
            let t = 0;
            while (i < expression.length && isDigit(expression[i])) {
                t = t * 10 + expression[i].charCodeAt() - '0'.charCodeAt();
                i++;
            }
            ops.push(t);
        }
    }
    const dp = new Array(ops.length).fill(0).map(() => new Array(ops.length).fill(0));
    for (let i = 0; i < ops.length; i++) {
        for (let j = 0; j < ops.length; j++) {
            dp[i][j] = [];
        }
    }
    return dfs(dp, 0, ops.length - 1, ops);
};

const dfs = (dp, l, r, ops) => {
    if (dp[l][r].length === 0) {
        if (l == r) {
            dp[l][r].push(ops[l]);
        } else {
            for (let i = l; i < r; i += 2) {
                const left = dfs(dp, l, i, ops);
                const right = dfs(dp, i + 2, r, ops);
                for (const lv of left) {
                    for (const rv of right) {
                        if (ops[i + 1] === ADDITION) {
                            dp[l][r].push(lv + rv);
                        } else if (ops[i + 1] === SUBTRACTION) {
                            dp[l][r].push(lv - rv);
                        } else {
                            dp[l][r].push(lv * rv);
                        }
                    }
                }
            }
        }
    }
    return dp[l][r];
}

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}
