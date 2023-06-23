﻿const T = 243;
const N = 5;
const M = 6;

const score = [
    [0, 0, 0],
    [0, -60, -10],
    [0, -10, 40]
];

function getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) {
    let tot = Math.pow(3, n);
    let maskBits = new Array(T).fill(0).map(() => new Array(N).fill(0));
    let ivCount = new Array(T).fill(0);
    let evCount = new Array(T).fill(0);
    let innerScore = new Array(T).fill(0);
    let interScore = new Array(T).fill(0).map(() => new Array(T).fill(0));
    let d = new Array(N).fill(0).map(() => new Array(T).fill(0).map(() => new Array(M + 1).fill(0).map(() => new Array(M + 1).fill(-1))));

    initData();

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < T; j++) {
            for (let k = 0; k <= M; k++) {
                d[i][j][k].fill(-1);
            }
        }
    }

    return dfs(0, 0, introvertsCount, extrovertsCount);

    function initData() {
        for (let mask = 0; mask < tot; mask++) {
            let maskTmp = mask;
            for (let i = 0; i < n; i++) {
                let x = maskTmp % 3;
                maskBits[mask][i] = x;
                maskTmp = Math.floor(maskTmp / 3);
                if (x === 1) {
                    ivCount[mask]++;
                    innerScore[mask] += 120;
                } else if (x === 2) {
                    evCount[mask]++;
                    innerScore[mask] += 40;
                }
                if (i > 0) {
                    innerScore[mask] += score[x][maskBits[mask][i - 1]];
                }
            }
        }

        for (let i = 0; i < tot; i++) {
            for (let j = 0; j < tot; j++) {
                interScore[i][j] = 0;
                for (let k = 0; k < n; k++) {
                    interScore[i][j] += score[maskBits[i][k]][maskBits[j][k]];
                }
            }
        }
    }

    function dfs(row, premask, iv, ev) {
        if (row === m || (iv === 0 && ev === 0)) {
            return 0;
        }

        if (d[row][premask][iv][ev] !== -1) {
            return d[row][premask][iv][ev];
        }

        let res = 0;
        for (let mask = 0; mask < tot; mask++) {
            if (ivCount[mask] > iv || evCount[mask] > ev) {
                continue;
            }

            res = Math.max(
                res,
                dfs(row + 1, mask, iv - ivCount[mask], ev - evCount[mask]) +
                innerScore[mask] +
                interScore[premask][mask]
            );
        }

        d[row][premask][iv][ev] = res;
        return res;
    }
}