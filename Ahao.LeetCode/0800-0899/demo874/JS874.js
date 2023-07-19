﻿var robotSim = function(commands, obstacles) {
    const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];
    let px = 0, py = 0, d = 1;
    let set = new Set();
    for (const obstacle of obstacles) {
        set.add(obstacle[0] * 60001 + obstacle[1]);
    }
    let res = 0;
    for (const c of commands) {
        if (c < 0) {
            d += c == -1 ? 1 : 3;
            d %= 4;
        } else {
            for (let i = 0; i < c; i++) {
                if (set.has((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                    break;
                }
                px += dirs[d][0];
                py += dirs[d][1];
                res = Math.max(res, px * px + py * py);
            }
        }
    }
    return res;
}
