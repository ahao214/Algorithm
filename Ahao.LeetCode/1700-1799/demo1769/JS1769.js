var minOperations = function(boxes) {
    const n = boxes.length;
    const res = [];
    for (let i = 0; i < n; i++) {
        let sm = 0;
        for (let j = 0; j < n; j++) {
            if (boxes[j] === '1') {
                sm += Math.abs(j - i);
            }
        }
        res.push(sm);
    }
    return res;
};



var minOperations = function (boxes) {
    let left = boxes[0].charCodeAt() - '0'.charCodeAt(), right = 0, operations = 0;
    const n = boxes.length;
    for (let i = 1; i < n; i++) {
        if (boxes[i] === '1') {
            right++;
            operations += i;
        }
    }
    const res = new Array(n).fill(0);
    res[0] = operations;
    for (let i = 1; i < n; i++) {
        operations += left - right;
        if (boxes[i] === '1') {
            left++;
            right--;
        }
        res[i] = operations;
    }
    return res;
}
