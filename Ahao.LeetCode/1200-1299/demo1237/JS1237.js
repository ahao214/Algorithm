function CustomFunction() {
    this.f = function (x, y) {

    };
};


var findSolution = function (customfunction, z) {
    const res = [];
    for (let x = 1; x <= 1000; x++) {
        for (let y = 1; y <= 1000; y++) {
            if (customfunction.f(x, y) === z) {
                res.push([x, y]);
            }
        }
    }
    return res;
};


var findSolution = function (customfunction, z) {
    const res = [];
    for (let x = 1; x <= 1000; x++) {
        let yleft = 1, yright = 1000;
        while (yleft <= yright) {
            const ymiddle = Math.floor((yleft + yright) / 2);
            if (customfunction.f(x, ymiddle) === z) {
                res.push([x, ymiddle]);
                break;
            }
            if (customfunction.f(x, ymiddle) > z) {
                yright = ymiddle - 1;
            } else {
                yleft = ymiddle + 1;
            }
        }
    }
    return res;
};

var findSolution = function (customfunction, z) {
    const res = [];
    for (let x = 1, y = 1000; x <= 1000 && y >= 1; x++) {
        while (y >= 1 && customfunction.f(x, y) > z) {
            y--;
        }
        if (y >= 1 && customfunction.f(x, y) === z) {
            res.push([x, y]);
        }
    }
    return res;
};
