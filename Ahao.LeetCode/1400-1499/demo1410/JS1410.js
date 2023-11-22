﻿var entityParser = function (text) {
    const entityMap = {
        "&quot;": '"',
        "&apos;": "'",
        "&gt;": ">",
        "&lt;": "<",
        "&frasl;": "/",
        "&amp;": "&",
    };

    let i = 0;
    const n = text.length;
    const res = [];

    while (i < n) {
        let isEntity = false;
        if (text[i] === "&") {
            for (const [key, value] of Object.entries(entityMap)) {
                if (text.slice(i, i + key.length) === key) {
                    res.push(value);
                    isEntity = true;
                    i += key.length;
                    break;
                }
            }
        }
        if (!isEntity) {
            res.push(text[i]);
            i += 1;
        }
    }
    return res.join("");
};
