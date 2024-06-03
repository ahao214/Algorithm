function distributeCandiesTS(candies: number, num_people: number): number[] {
    const ans: number[] = new Array(num_people).fill(0);
    let i: number = 0;
    while (candies !== 0) {
        ans[i % num_people] += Math.min(candies, i + 1);
        candies -= Math.min(candies, i + 1);
        i++;
    }
    return ans;
};



function distributeCandiesTS2(candies: number, num_people: number): number[] {
    const n: number = num_people;
    // how many people received complete gifts
    const p: number = Math.floor(Math.sqrt(2 * candies + 0.25) - 0.5);
    const remaining: number = candies - Math.floor((p + 1) * p * 0.5);
    const rows: number = Math.floor(p / n), cols: number = p % n;
    const d: number[] = new Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        // Complete rows
        d[i] = (i + 1) * rows + Math.floor(rows * (rows - 1) * 0.5) * n;
        // Columns in the last row
        if (i < cols) {
            d[i] += i + 1 + rows * n;
        }
    }
    // Remaining candies
    d[cols] += remaining;

    return d;
};
