var minFallingPathSum = function (grid) {
    const n = grid.length;
    const d = new Array(n).fill(0).map(() => new Array(n).fill(Infinity));
    for (let i = 0; i < n; i++) {
        d[0][i] = grid[0][i];
    }
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                if (j == k) {
                    continue;
                }
                d[i][j] = Math.min(d[i][j], d[i - 1][k] + grid[i][j]);
            }
        }
    }
    return Math.min(...d[n - 1]);
};



var minFallingPathSum = function (grid) {
    const n = grid.length;
    let first_min_sum = 0, second_min_sum = 0;
    let first_min_index = -1;

    for (let i = 0; i < n; i++) {
        let cur_first_min_sum = Infinity, cur_second_min_sum = Infinity;
        let cur_first_min_index = -1;

        for (let j = 0; j < n; j++) {
            let cur_sum = grid[i][j];
            if (j != first_min_index) {
                cur_sum += first_min_sum;
            } else {
                cur_sum += second_min_sum;
            }
            if (cur_sum < cur_first_min_sum) {
                cur_second_min_sum = cur_first_min_sum;
                cur_first_min_sum = cur_sum;
                cur_first_min_index = j
            } else if (cur_sum < cur_second_min_sum) {
                cur_second_min_sum = cur_sum;
            }
        }
        first_min_sum = cur_first_min_sum;
        second_min_sum = cur_second_min_sum;
        first_min_index = cur_first_min_index;
    }
    return first_min_sum;
};
