﻿var strongPasswordCheckerII = function (password) {
    if (password.length < 8) {
        return false;
    }

    const specials = new Set();
    specials.add('!');
    specials.add('@');
    specials.add('#');
    specials.add('$');
    specials.add('%');
    specials.add('^');
    specials.add('&');
    specials.add('*');
    specials.add('(');
    specials.add(')');
    specials.add('-');
    specials.add('+');
    const n = password.length;
    let hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (let i = 0; i < n; ++i) {
        if (i !== n - 1 && password[i] === password[i + 1]) {
            return false;
        }

        const ch = password[i];
        if (isLowerCase(ch)) {
            hasLower = true;
        } else if (isUpperCase(ch)) {
            hasUpper = true;
        } else if (isDigit(ch)) {
            hasDigit = true;
        } else if (specials.has(ch)) {
            hasSpecial = true;
        }
    }
    return hasLower && hasUpper && hasDigit && hasSpecial;
};

const isDigit = (ch) => {
    return parseFloat(ch).toString() === "NaN" ? false : true;
}

const isLowerCase = str => 'a' <= str && str <= 'z';

const isUpperCase = str => 'A' <= str && str <= 'Z';
