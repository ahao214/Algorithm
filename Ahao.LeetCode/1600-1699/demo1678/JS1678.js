﻿var interpret = function (command) {
    let res = '';
    for (let i = 0; i < command.length; i++) {
        if (command[i] === 'G') {
            res += 'G';
        } else if (command[i] === '(') {
            if (command[i + 1] === ')') {
                res += 'o';
            } else {
                res += 'al';
            }
        }
    }
    return res;
};
