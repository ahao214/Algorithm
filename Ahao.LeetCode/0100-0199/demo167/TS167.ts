//Map
function twoSum(numbers: number[], target: number): number[] {
    let map = new Map()
    for (let i = 0; i < numbers.length; i++) {
        map.set(numbers[i], i)
    }
    for (let i = 0; i < numbers.length; i++) {
        if (map.has(target - numbers[i])) {
            return [i + 1, map.get(target - numbers[i]) + 1]
        }
    }
};



//双指针
function twoSumTwoPoint(numbers: number[], target: number): number[] {
    let left = 0, right = numbers.length - 1;
    while (left < right) {
        if (numbers[left] + numbers[right] === target) {
            return [++left, ++right];
        }
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else {
            left++;
        }
    }
};


//二分查找
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
function twoSumBinary(numbers: number[], target: number): number[] {
    for (let i = 0; i < numbers.length; i++) {
        let targ = target - numbers[i]
        let l = i + 1, r = numbers.length - 1
        while (l <= r) {
            let mid = Math.floor((l + r) / 2)
            let num = numbers[mid]
            if (targ === num) return [i + 1, mid + 1]
            if (targ > num) {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
};

