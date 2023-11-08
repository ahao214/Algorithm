var fullBloomFlowers = function (flowers, people) {
    const cnt = new Map();
    for (const [start, end] of flowers) {
        cnt.set(start, cnt.has(start) ? cnt.get(start) + 1 : 1);
        cnt.set(end + 1, cnt.has(end + 1) ? cnt.get(end + 1) - 1 : -1);
    }
    const arr = [];
    for (let item of cnt.entries()) {
        arr.push([item[0], item[1]]);
    }
    arr.sort((a, b) => a[0] - b[0]);
    let m = people.length;
    indices = Array.from(new Array(m).keys())
    indices.sort((a, b) => people[a] - people[b]);
    let j = 0, curr = 0;
    let ans = new Array(m).fill(0);
    for (const i of indices) {
        while (j < arr.length && arr[j][0] <= people[i]) {
            curr += arr[j][1];
            j += 1;
        }
        ans[i] = curr;
    }
    return ans;
};




var fullBloomFlowers = function (flowers, people) {
    const starts = flowers.map((item) => item[0]);
    const ends = flowers.map((item) => item[1]);
    starts.sort((a, b) => a - b);
    ends.sort((a, b) => a - b);

    var binarySearch = function (arr, target) {
        let res = arr.length;
        let left = 0, right = arr.length - 1;
        while (left <= right) {
            let mid = (left + right) >> 1;
            if (arr[mid] >= target) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
    const m = people.length;
    const ans = new Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        const p = people[i];
        ans[i] = binarySearch(starts, p + 1) - binarySearch(ends, p);
    }
    return ans;
};
