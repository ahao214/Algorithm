﻿var isRobotBounded = function (instructions) {
    const direc = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    let direcIndex = 0
    let x = 0, y = 0
    const n = instructions.length
    for (let i = 0; i < n; i++) {
        let instruction = instructions[i]
        if (instruction === 'G') {
            x += direc[direcIndex][0]
            y += direc[direcIndex][1]
        } else if (instruction === 'L') {
            direcIndex += 3
            direcIndex %= 4
        } else {
            direcIndex++
            direcIndex %= 4
        }
    }
    return direcIndex !== 0 || (x === 0 && y === 0)
}
