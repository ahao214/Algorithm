function accountBalanceAfterPurchaseTS1(purchaseAmount: number): number {
    const r = purchaseAmount % 10;
    if (r < 5) {
        purchaseAmount -= r;
    } else {
        purchaseAmount += 10 - r;
    }
    return 100 - purchaseAmount;
};



function accountBalanceAfterPurchaseTS2(purchaseAmount: number): number {
    return 100 - Math.floor((purchaseAmount + 5) / 10) * 10;
};

