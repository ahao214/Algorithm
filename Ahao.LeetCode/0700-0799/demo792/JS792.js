//二分查找
var numMatchingSubseq = function (s, words) {
    const pos = new Array(26).fill(0).map(() => new Array());
    for (let i = 0; i < s.length; ++i) {
        pos[s[i].charCodeAt() - 'a'.charCodeAt()].push(i);
    }
    let res = words.length;
    for (const w of words) {
        if (w.length > s.length) {
            --res;
            continue;
        }
        let p = -1;
        for (let i = 0; i < w.length; ++i) {
            const c = w[i];
            if (pos[c.charCodeAt() - 'a'.charCodeAt()].length === 0 || pos[c.charCodeAt() - 'a'.charCodeAt()][pos[c.charCodeAt() - 'a'.charCodeAt()].length - 1] <= p) {
                --res;
                break;
            }
            p = binarySearch(pos[c.charCodeAt() - 'a'.charCodeAt()], p);
        }
    }
    return res;
}

const binarySearch = (list, target) => {
    let left = 0, right = list.length - 1;
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        if (list[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return list[left];
};


//多指针
var numMatchingSubseq = function (s, words) {
    const p = new Array(26).fill(0).map(() => new Array());
    for (let i = 0; i < words.length; ++i) {
        p[words[i][0].charCodeAt() - 'a'.charCodeAt()].push([i, 0]);
    }
    let res = 0;
    for (let i = 0; i < s.length; ++i) {
        const c = s[i];
        let len = p[c.charCodeAt() - 'a'.charCodeAt()].length;
        while (len > 0) {
            const t = p[c.charCodeAt() - 'a'.charCodeAt()].shift();
            if (t[1] === words[t[0]].length - 1) {
                ++res;
            } else {
                ++t[1];
                p[words[t[0]][t[1]].charCodeAt() - 'a'.charCodeAt()].push(t);
            }
            --len;
        }
    }
    return res;
}
