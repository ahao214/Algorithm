﻿var findingUsersActiveMinutes = function (logs, k) {
    const activeMinutes = new Map();
    for (const [id, time] of logs) {
        if (!activeMinutes.has(id)) {
            activeMinutes.set(id, new Set());
        }
        activeMinutes.get(id).add(time);
    }
    const answer = new Array(k).fill(0);
    for (const minutes of activeMinutes.values()) {
        const activeCount = minutes.size;
        answer[activeCount - 1]++;
    }
    return answer;
};
