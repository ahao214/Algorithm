﻿const POLE_NUM = 10;
const COLOR_NUM = 3;

var countPoints = function (rings) {
    const getColorId = function (color) {
        if (color == 'R') {
            return 0;
        } else if (color == 'G') {
            return 1;
        }
        return 2;
    }

    const state = new Array(POLE_NUM).fill(0).map(() => new Array(COLOR_NUM).fill(0));
    const n = rings.length;
    for (let i = 0; i < n; i += 2) {
        const color = rings[i];
        const pole_index = rings[i + 1] - '0';
        state[pole_index][getColorId(color)] = 1;
    }
    let res = 0
    for (let i = 0; i < POLE_NUM; i++) {
        flag = true
        for (let j = 0; j < COLOR_NUM; j++) {
            if (state[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res++;
        }
    }
    return res;
};



const POLE_NUM = 10;

var countPoints = function (rings) {
    const state = new Array(POLE_NUM).fill(0);
    const n = rings.length;
    for (let i = 0; i < n; i += 2) {
        const color = rings[i];
        const pole_index = rings[i + 1] - '0';
        if (color == 'R') {
            state[pole_index] |= 1;
        } else if (color == 'G') {
            state[pole_index] |= 2;
        } else {
            state[pole_index] |= 4;
        }
    }
    let res = 0;
    for (let i = 0; i < POLE_NUM; i++) {
        res += state[i] == 7;
    }
    return res;
};
