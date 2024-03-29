﻿var toGoatLatin = function (sentence) {
    const vowels = new Set();
    vowels.add('a');
    vowels.add('e');
    vowels.add('i');
    vowels.add('o');
    vowels.add('u');
    vowels.add('A');
    vowels.add('E');
    vowels.add('I');
    vowels.add('O');
    vowels.add('U');

    const n = sentence.length;
    let i = 0, cnt = 1;
    ans = '';

    while (i < n) {
        let j = i;
        while (j < n && sentence[j] !== ' ') {
            ++j;
        }

        ++cnt;
        if (cnt !== 2) {
            ans += ' ';
        }
        if (vowels.has(sentence[i])) {
            ans += sentence.substring(i, j);
        } else {
            ans += sentence.slice(i + 1, j);
            ans += sentence[i];
        }
        ans += 'm';
        for (let k = 0; k < cnt; ++k) {
            ans += 'a';
        }

        i = j + 1;
    }

    return ans;
};
