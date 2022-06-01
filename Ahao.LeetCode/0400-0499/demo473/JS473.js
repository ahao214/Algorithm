﻿//回溯
var makesquare = function (matchsticks) {
    const totalLen = _.sum(matchsticks);
    if (totalLen % 4 !== 0) {
        return false;
    }
    matchsticks.sort((a, b) => a - b);
    for (let i = 0, j = matchsticks.length - 1; i < j; i++, j--) {
        const temp = matchsticks[i];
        matchsticks[i] = matchsticks[j];
        matchsticks[j] = temp;
    }

    const edges = new Array(4).fill(0);
    return dfs(0, matchsticks, edges, Math.floor(totalLen / 4));
}

const dfs = (index, matchsticks, edges, len) => {
    if (index === matchsticks.length) {
        return true;
    }
    for (let i = 0; i < edges.length; i++) {
        edges[i] += matchsticks[index];
        if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
            return true;
        }
        edges[i] -= matchsticks[index];
    }
    return false;
};


//方法二：状态压缩 + 动态规划
func makesquare(matchsticks[]int) bool {
    totalLen:= 0
    for _, l := range matchsticks {
        totalLen += l
    }
    if totalLen % 4 != 0 {
        return false
    }

    tLen:= totalLen / 4
    dp:= make([]int, 1 << len(matchsticks))
    for i := 1; i < len(dp); i++ {
        dp[i] = -1
    }
    for s := 1; s < len(dp); s++ {
        for k, v := range matchsticks {
            if s >> k & 1 == 0 {
                continue
            }
            s1:= s &^ (1 << k)
            if dp[s1] >= 0 && dp[s1] + v <= tLen {
                dp[s] = (dp[s1] + v) % tLen
                break
            }
        }
    }
    return dp[len(dp) - 1] == 0
}

