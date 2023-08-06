function twoSum(nums: number[], target: number): number[] {
    const len: number = nums.length;
    if (len > 1) {
        let map: Map<number, any> = new Map();
        for (let i = 0; i < len; i++) {
            const num = nums[i];
            const diff = target - num;
            if (map.has(diff)) {
                return [map.get(diff), i]
            }
            map.set(num, i);
        }
    }
    return [];
}

function twoSum2(nums: number[], target: number): number[] {
    const len: number = nums.length;
    const res: number[] = [];
    if (len > 1) {
        let map: Map<number, any> = new Map();
        nums.forEach((n, i) => {
            const diff: number = target - n;
            if (map.has(diff)) {
                res.push(map.get(diff), i);
            }
            map.set(n, i);
        })
    }
    return res;
};


function twoSum3(nums: number[], target: number): number[] {
    const len: number = nums.length;
    if (len > 1) {
        for (let i = 0; i < len; i++) {
            for (let j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return [i, j];
                }
            }
        }
    }
    return []
}

function twoSum4(nums: number[], target: number): number[] {
    const len: number = nums.length;
    if (len > 1) {
        for (let i = 0; i < len; i++) {
            const diff: number = nums[i];
            const index: number = nums.indexOf(target - diff, i + 1);
            if (index != -1) {
                return [i, index];
            }
        }
    }
    return [];
}