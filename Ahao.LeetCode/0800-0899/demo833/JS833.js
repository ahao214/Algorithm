﻿var findReplaceString = function (s, indices, sources, targets) {
    const n = s.length;
    const m = indices.length;

    const ops = new Array(m);
    for (let i = 0; i < m; i++) {
        ops[i] = i;
    }
    ops.sort((i, j) => indices[i] - indices[j]);

    let ans = "";
    let pt = 0;
    for (let i = 0; i < n;) {
        while (pt < m && indices[ops[pt]] < i) {
            pt++;
        }
        let found = false;
        while (pt < m && indices[ops[pt]] == i) {
            if (s.substring(i, i + sources[ops[pt]].length) === sources[ops[pt]]) {
                found = true;
                break;
            }
            pt++;
        }
        if (found) {
            ans += targets[ops[pt]];
            i += sources[ops[pt]].length;
        } else {
            ans += s[i];
            i++;
        }
    }
    return ans;
};



