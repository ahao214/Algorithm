//模拟+队列
var findTheWinner = function (n, k) {
    const queue = [];
    for (let i = 1; i <= n; i++) {
        queue.push(i);
    }
    while (queue.length > 1) {
        for (let i = 1; i < k; i++) {
            queue.push(queue.shift());
        }
        queue.shift();
    }
    return queue[0];
};


//数字+递归
var findTheWinner = function (n, k) {
    if (n === 1) {
        return 1;
    }
    return (k + findTheWinner(n - 1, k) - 1) % n + 1;
};


//数字+迭代
var findTheWinner = function (n, k) {
    let winner = 1;
    for (let i = 2; i <= n; i++) {
        winner = (k + winner - 1) % i + 1;
    }
    return winner;
};
