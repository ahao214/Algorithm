var twoSum = function (numbers, target) {
    let left = 0;
    let right = numbers.length - 1;

    if (numbers.length <= 2) {
        return [++left, ++right];
    }

    while (left < right) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            return [++left, ++right];
        }
    }
};
