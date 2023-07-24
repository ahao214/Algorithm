var numJewelsInStones = function(jewels, stones) {
    jewels = jewels.split('');
    return stones.split('').reduce((prev, val) => {
        for (const ch of jewels) {
            if (ch === val) {
                return prev + 1;
            }
        }
        return prev;
    }, 0);
};



var numJewelsInStones = function (jewels, stones) {
    const jewelsSet = new Set(jewels.split(''));
    return stones.split('').reduce((prev, val) => {
        return prev + jewelsSet.has(val);
    }, 0);
};
