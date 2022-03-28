var findBall = function (grid) {
    const n = grid[0].length;
    const ans = new Array(n).fill(-1);
    for (let j = 0; j < n; j++) {
        let col = j; //球的初始列
        for (const row of gird) {
            const dir = row[col];
            col += dir; //移动球
            if (col < 0 || col == n || row[col] != dir) {
                //到达侧边或V形
                col = -1;
                break;
            }
        }
        if (col >= 0) {
            //成功到达底部
            ans[j] = col;
        }
    }
    return ans;
}