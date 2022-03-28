var reversePrefix = function (word, ch) {
    const index = word.indexOf(ch);
    if (index >= 0) {
        const arr = [...word];
        let left = 0,
            right = index;
        while (left < right) {
            const tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
        word = arr.join('');
    }
    return word;
};