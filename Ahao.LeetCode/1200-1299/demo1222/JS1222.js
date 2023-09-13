var queensAttacktheKing = function(queens, king) {
    queen_pos = new Set();
    for (const queen of queens) {
        let x = queen[0], y = queen[1];
        queen_pos.add(x * 8 + y);
    }

    const ans = [];
    for (let dx = -1; dx <= 1; ++dx) {
        for (let dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            let kx = king[0] + dx, ky = king[1] + dy;
            while (kx >= 0 && kx < 8 && ky >= 0 && ky < 8) {
                let pos = kx * 8 + ky;
                if (queen_pos.has(pos)) {
                    ans.push([kx, ky]);
                    break;
                }
                kx += dx;
                ky += dy;
            }
        }
    }
    return ans;
};





var queensAttacktheKing = function (queens, king) {
    const sgn = function (x) {
        return x > 0 ? 1 : (x == 0 ? 0 : -1);
    }

    const candidates = new Map();
    const kx = king[0], ky = king[1];
    for (const queen of queens) {
        let qx = queen[0], qy = queen[1];
        let x = qx - kx, y = qy - ky;
        if (x == 0 || y == 0 || Math.abs(x) == Math.abs(y)) {
            let dx = sgn(x), dy = sgn(y);
            const key = dx * 10 + dy;
            if (!candidates.has(key) || candidates.get(key)[2] > Math.abs(x) + Math.abs(y)) {
                candidates.set(key, [qx, qy, Math.abs(x) + Math.abs(y)]);
            }
        }
    }

    const ans = [];
    for (let value of candidates.values()) {
        ans.push([value[0], value[1]]);
    }
    return ans;
};
