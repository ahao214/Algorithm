﻿//枚举
var maximalNetworkRank = function (n, roads) {
    const connect = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const degree = new Array(n).fill(0);
    for (const v of roads) {
        connect[v[0]][v[1]] = true;
        connect[v[1]][v[0]] = true;
        degree[v[0]]++;
        degree[v[1]]++;
    }

    let maxRank = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
            maxRank = Math.max(maxRank, rank);
        }
    }
    return maxRank;
};



//贪心
var maximalNetworkRank = function (n, roads) {
    const connect = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const degree = new Array(n).fill(0);
    for (const road of roads) {
        let x = road[0], y = road[1];
        connect[x][y] = true;
        connect[y][x] = true;
        degree[x]++;
        degree[y]++;
    }

    let first = -1, second = -2;
    let firstArr = [];
    let secondArr = [];
    for (let i = 0; i < n; ++i) {
        if (degree[i] > first) {
            second = first;
            secondArr = [...firstArr];
            first = degree[i];
            firstArr = [i];
        } else if (degree[i] === first) {
            firstArr.push(i);
        } else if (degree[i] > second) {
            secondArr = [];
            second = degree[i];
            secondArr.push(i);
        } else if (degree[i] === second) {
            secondArr.push(i);
        }
    }
    if (firstArr.length === 1) {
        const u = firstArr[0];
        for (const v of secondArr) {
            if (!connect[u][v]) {
                return first + second;
            }
        }
        return first + second - 1;
    } else {
        const m = roads.length;
        if (firstArr.length * (firstArr.length - 1) / 2 > m) {
            return first * 2;
        }
        for (const u of firstArr) {
            for (const v of firstArr) {
                if (u !== v && !connect[u][v]) {
                    return first * 2;
                }
            }
        }
        return first * 2 - 1;
    }
};
