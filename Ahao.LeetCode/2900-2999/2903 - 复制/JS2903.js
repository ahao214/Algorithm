﻿function maximumLengthTS(s: string): number {
    let ans = -1;
    const len = s.length;
    const chs: number[][] = Array.from({ length: 26 }, () => []);
    let cnt = 0;

    for (let i = 0; i < len; i++) {
        cnt++;
        if (i + 1 === len || s[i] !== s[i + 1]) {
            const ch = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
            chs[ch].push(cnt);
            cnt = 0;
            for (let j = chs[ch].length - 1; j > 0; j--) {
                if (chs[ch][j] > chs[ch][j - 1]) {
                    [chs[ch][j], chs[ch][j - 1]] = [chs[ch][j - 1], chs[ch][j]];
                } else {
                    break;
                }
            }
            if (chs[ch].length > 3) {
                chs[ch].pop();
            }
        }
    }

    for (let i = 0; i < 26; i++) {
        if (chs[i].length > 0 && chs[i][0] > 2) {
            ans = Math.max(ans, chs[i][0] - 2);
        }
        if (chs[i].length > 1 && chs[i][0] > 1) {
            ans = Math.max(ans, Math.min(chs[i][0] - 1, chs[i][1]));
        }
        if (chs[i].length > 2) {
            ans = Math.max(ans, chs[i][2]);
        }
    }

    return ans;
};
