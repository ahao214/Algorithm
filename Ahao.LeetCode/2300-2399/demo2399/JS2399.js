var checkDistances = function (s, distance) {
    let n = s.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (s[i] == s[j] && distance[s.charCodeAt(i) - 'a'.charCodeAt(0)] != j - i - 1) {
                return false;
            }
        }
    }
    return true;
};


var checkDistances = function (s, distance) {
    let firstIndex = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        let idx = s.charCodeAt(i) - 'a'.charCodeAt(0);
        if (firstIndex[idx] != 0 && i - firstIndex[idx] != distance[idx]) {
            return false;
        }
        firstIndex[idx] = i + 1;
    }
    return true;
};
