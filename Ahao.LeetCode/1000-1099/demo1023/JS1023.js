﻿var camelMatch = function(queries, pattern) {
    let n = queries.length
    let res = new Array(n)
    for (let i = 0; i < n; i++) {
        res[i] = true
        let p = 0
        for (let j = 0; j < queries[i].length; j++) {
            let c = queries[i][j]
            if (p < pattern.length && pattern[p] === c) {
                p++
            } else if (c.toUpperCase() === c) {
                res[i] = false
                break
            }
        }
        if (p < pattern.length) {
            res[i] = false
        }
    }
    return res
};
