function specialPerm(nums: number[]): number {
    const mod: number = 1e9 + 7;
    const n: number = nums.length;
    const f: number[][] = new Array(1 << n).fill([]).map(() => new Array(n).fill(-1));

    const dfs = (state: number, i: number): number => {
        if (f[state][i] !== -1) {
            return f[state][i];
        }
        if (state === (1 << i)) {
            return 1;
        }
        f[state][i] = 0;
        for (let j = 0; j < n; j++) {
            if (i === j || !(state >> j & 1)) {
                continue;
            }
            if (nums[i] % nums[j] !== 0 && nums[j] % nums[i] !== 0) {
                continue;
            }
            f[state][i] = (f[state][i] + dfs(state ^ (1 << i), j)) % mod;
        }
        return f[state][i];
    };

    let res: number = 0;
    for (let i = 0; i < n; i++) {
        res = (res + dfs((1 << n) - 1, i)) % mod;
    }
    return res;
};



const MOD: number = 1000000007;

function specialPermTS(nums: number[]): number {
    const n: number = nums.length;
    const f: number[][] = Array.from(Array(1 << n), () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        f[1 << i][i] = 1;
    }

    for (let state = 1; state < (1 << n); state++) {
        for (let i = 0; i < n; i++) {
            if (!(state >> i & 1)) {
                continue;
            }
            for (let j = 0; j < n; j++) {
                if (i === j || !(state >> j & 1)) {
                    continue;
                }
                const x: number = nums[i];
                const y: number = nums[j];
                if (x % y !== 0 && y % x !== 0) {
                    continue;
                }
                f[state][i] = (f[state][i] + f[state ^ (1 << i)][j]) % MOD;
            }
        }
    }

    let sum: number = 0;
    for (let i = 0; i < n; i++) {
        sum = (sum + f[(1 << n) - 1][i]) % MOD;
    }

    return sum;
};
