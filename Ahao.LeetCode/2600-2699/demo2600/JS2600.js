﻿var kItemsWithMaximumSum = function (numOnes, numZeros, numNegOnes, k) {
    if (k <= numOnes) {
        return k;
    } else if (k <= numOnes + numZeros) {
        return numOnes;
    } else {
        return numOnes - (k - numOnes - numZeros);
    }
};

