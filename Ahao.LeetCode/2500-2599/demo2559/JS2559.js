﻿var vowelStrings = function (words, queries) {
    let n = words.length;
    let prefixSums = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        let value = isVowelString(words[i]) ? 1 : 0;
        prefixSums[i + 1] = prefixSums[i] + value;
    }
    let ans = [];
    for (let i = 0; i < queries.length; i++) {
        let start = queries[i][0], end = queries[i][1];
        ans.push(prefixSums[end + 1] - prefixSums[start]);
    }
    return ans;
}

function isVowelString(word) {
    return isVowelLetter(word[0]) && isVowelLetter(word[word.length - 1]);
}

function isVowelLetter(c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
