var minimumPerimeter = function (neededApples) {
    let n = 1;
    while (2 * n * (n + 1) * (2 * n + 1) < neededApples) {
        n++;
    }
    return n * 8;
};


var minimumPerimeter = function (neededApples) {
    let left = 1, right = 100000, ans = 0;
    while (left <= right) {
        const mid = (left + right) >> 1;
        if (2 * mid * (mid + 1) * (mid * 2 + 1) >= neededApples) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans * 8;
};
