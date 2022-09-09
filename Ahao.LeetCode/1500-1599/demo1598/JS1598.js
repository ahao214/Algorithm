﻿var minOperations = function (logs) {
    let depth = 0;
    for (const log of logs) {
        if ('./' === log) {
            continue;
        } else if ('../' === log) {
            if (depth > 0) {
                depth--;
            }
        } else {
            depth++;
        }
    }
    return depth;
};
