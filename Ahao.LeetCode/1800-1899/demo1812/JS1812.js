﻿var squareIsWhite = function (coordinates) {
    return ((coordinates[0].charCodeAt() - 'a'.charCodeAt() + 1) + (coordinates[1].charCodeAt() - '0'.charCodeAt())) % 2 === 1;
};
