//方法一：排序
var numberOfWeakCharacters = function (properties) {
    properties.sort((o1, o2) => {
        return o1[0] === o2[0] ? (o1[1] - o2[1]) : (o2[0] - o1[0]);
    });
    let maxDef = 0;
    let ans = 0;
    for (const p of properties) {
        if (p[1] < maxDef) {
            ans++;
        } else {
            maxDef = p[1];
        }
    }
    return ans;
};

//方法二：单调栈
var numberOfWeakCharacters2 = function (properties) {
    properties.sort((o1, o2) => {
        return o1[0] === o2[0] ? (o2[1] - o1[1]) : (o1[0] - o2[0]);
    });
    let ans = 0;
    const st = [];
    for (const p of properties) {
        while (st.length && st[st.length - 1] < p[1]) {
            st.pop();
            ans++;
        }
        st.push(p[1]);
    }
    return ans;
};