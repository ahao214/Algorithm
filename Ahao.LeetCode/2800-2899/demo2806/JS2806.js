var accountBalanceAfterPurchase = function (purchaseAmount) {
    const r = purchaseAmount % 10;
    if (r < 5) {
        purchaseAmount -= r;
    } else {
        purchaseAmount += 10 - r;
    }
    return 100 - purchaseAmount;
};


var accountBalanceAfterPurchase = function (purchaseAmount) {
    return 100 - Math.floor((purchaseAmount + 5) / 10) * 10;
};
