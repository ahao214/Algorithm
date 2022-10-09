//方法一：分治
var scoreOfParentheses = function (s) {
    if (s.length === 2) {
        return 1;
    }
    let bal = 0, n = s.length, len = 0;
    for (let i = 0; i < n; i++) {
        bal += (s[i] === '(' ? 1 : -1);
        if (bal === 0) {
            len = i + 1;
            break;
        }
    }
    if (len === n) {
        return 2 * scoreOfParentheses(s.slice(1, n - 1));
    } else {
        return scoreOfParentheses(s.slice(0, len)) + scoreOfParentheses(s.slice(len));
    }
};


//方法二：栈
var scoreOfParentheses = function (s) {
    const st = [0];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            st.push(0);
        } else {
            let v = st.pop();
            let top = st.pop() + Math.max(2 * v, 1);
            st.push(top);
        }
    }
    return st[0];
};


//方法三：计算最终分数和
var scoreOfParentheses = function (s) {
    let bal = 0, n = s.length, res = 0;
    for (let i = 0; i < n; i++) {
        bal += (s[i] == '(' ? 1 : -1);
        if (s[i] == ')' && s[i - 1] === '(') {
            res += 1 << bal;
        }
    }
    return res;
};


