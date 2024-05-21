function findWinnersTS(matches: number[][]): number[][] {
    const freq: Map<number, number> = new Map();
    for (const [winner, loser] of matches) {
        if (!freq.has(winner)) {
            freq.set(winner, 0);
        }
        freq.set(loser, (freq.get(loser) || 0) + 1);
    }

    const ans: number[][] = [[], []];
    for (const [key, value] of freq) {
        if (value < 2) {
            ans[value].push(key);
        }
    }

    ans[0].sort((a, b) => a - b);
    ans[1].sort((a, b) => a - b);
    return ans;
};
