﻿var maxProduct = function (words) {
    const length = words.length;
    const masks = new Array(length).fill(0);
    for (let i = 0; i < length; i++) {
        const word = words[i];
        const wordLength = word.length;
        for (let j = 0; j < wordLength; j++) {
            masks[i] |= 1 << (word[j].charCodeAt() - 'a'.charCodeAt());
        }
    }
    let maxProd = 0;
    for (let i = 0; i < length; i++) {
        for (let j = i + 1; j < length; j++) {
            if ((masks[i] & masks[j]) === 0) {
                maxProd = Math.max(maxProd, words[i].length * words[j].length);
            }
        }
    }
    return maxProd;
};



var maxProduct = function (words) {
    const map = new Map();
    const length = words.length;
    for (let i = 0; i < length; i++) {
        let mask = 0;
        const word = words[i];
        const wordLength = word.length;
        for (let j = 0; j < wordLength; j++) {
            mask |= 1 << (word[j].charCodeAt() - 'a'.charCodeAt());
        }
        if (wordLength > (map.get(mask) || 0)) {
            map.set(mask, wordLength);
        }
    }
    let maxProd = 0;
    const maskSet = Array.from(map.keys());
    for (const mask1 of maskSet) {
        const wordLength1 = map.get(mask1);
        for (const mask2 of maskSet) {
            if ((mask1 & mask2) === 0) {
                const wordLength2 = map.get(mask2);
                maxProd = Math.max(maxProd, wordLength1 * wordLength2);
            }
        }
    }
    return maxProd;
};
