﻿var minLength = function (s) {
    const st = new Array();
    for (const c of s) {
        st.push(c);
        let m = st.length;
        if (m >= 2 &&
            (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                st[m - 2] == 'C' && st[m - 1] == 'D')) {
            st.pop();
            st.pop();
        }
    }
    return st.length;
};
