/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */
var slowestKey = function (releaseTimes, keysPressed) {
    const n = releaseTimes.length;
    let ans = keysPressed[0];
    let longestTime = releaseTimes[0];
    for (let i = 1; i < n; i++) {
        let time = releaseTimes[i] - releaseTimes[i - 1];
        let key = keysPressed[i];
        if (time > longestTime || (time == longestTime && key > ans)) {
            ans = key;
            longestTime = time;
        }
    }
    return ans;
};