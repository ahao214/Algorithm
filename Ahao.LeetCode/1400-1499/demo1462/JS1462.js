﻿var checkIfPrerequisite = function (numCourses, prerequisites, queries) {
    let g = new Array(numCourses).fill(0).map(() => new Array());
    let indgree = new Array(numCourses).fill(0);
    let isPre = new Array(numCourses).fill(0).map(() => new Array(numCourses).fill(false));
    for (let p of prerequisites) {
        ++indgree[p[1]];
        g[p[0]].push(p[1]);
    }
    let q = [];
    for (let i = 0; i < numCourses; ++i) {
        if (indgree[i] == 0) {
            q.push(i);
        }
    }

    while (q.length) {
        let cur = q.shift();
        for (let ne of g[cur]) {
            isPre[cur][ne] = true;
            for (let i = 0; i < numCourses; ++i) {
                isPre[i][ne] = isPre[i][ne] || isPre[i][cur];
            }
            --indgree[ne];
            if (indgree[ne] == 0) {
                q.push(ne);
            }
        }
    }
    res = [];
    for (let query of queries) {
        res.push(isPre[query[0]][query[1]]);
    }
    return res;
};






