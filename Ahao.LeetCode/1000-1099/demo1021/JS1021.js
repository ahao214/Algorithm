//方法一： 栈
var removeOuterParentheses = function (s) {
    let res = '';
    const stack = [];
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (c === ')') {
            stack.pop();
        }
        if (stack.length) {
            res += c;
        }
        if (c === '(') {
            stack.push(c);
        }
    }
    return res;
};


//方法二：计数
var removeOuterParentheses = function (s) {
    let level = 0;
    let res = '';
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (c === ')') {
            level--;
        }
        if (level > 0) {
            res += c;
        }
        if (c === '(') {
            level++;
        }
    }
    return res;
};

