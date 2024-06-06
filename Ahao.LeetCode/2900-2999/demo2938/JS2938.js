var minimumSteps = function (s) {
    var res = 0;
    var sum = 0;
    for (var i = 0; i < s.length; i++) {
        if (s[i] == '1') {
            sum++;
        } else {
            res += sum;
        }
    }
    return res;
};