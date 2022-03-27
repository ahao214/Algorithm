/**
 * @param {character[][]} board
 * @return {number}
 */

//方法一：遍历扫描
var countBattleships = function (board) {
    const row = board.length;
    const col = board[0].length;
    let ans = 0;
    for (let i = 0; i < row; ++i) {
        for (let j = 0; j < col; ++j) {
            if (board[i][j] === 'X') {
                board[i][j] = '.';
                for (let k = j + 1; k < col && board[i][k] === 'X'; ++k) {
                    board[i][k] = '.';
                }
                for (let k = i + 1; k < row && board[k][j] === 'X'; ++k) {
                    board[k][j] = '.';
                }
                ans++;
            }
        }
    }
    return ans;
};

//方法二：枚举起点
var countBattleships2 = function (board) {
    const row = board.length;
    const col = board[0].length;
    let ans = 0;
    for (let i = 0; i < row; ++i) {
        for (let j = 0; j < col; ++j) {
            if (board[i][j] === 'X') {
                if (i > 0 && board[i - 1][j] === 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] === 'X') {
                    continue;
                }
                ans++;
            }
        }
    }
    return ans;
};