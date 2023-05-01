﻿var numOfMinutes = function (n, headID, manager, informTime) {
    // 构建树的邻接表，使用 Map 存储
    const g = new Map();

    // 定义深度优先遍历函数
    const dfs = (cur, informTime, g) => {
        // res 存储当前节点的所有下属中，最大的通知时间
        let res = 0;

        // 遍历当前节点的每个下属
        for (const neighbor of g.get(cur) || []) {
            // 递归计算下属的通知时间，并更新 res
            res = Math.max(res, dfs(neighbor, informTime, g));
        }

        // 返回当前节点的通知时间（加上下属中最大的通知时间）
        return informTime[cur] + res;
    };

    // 遍历每个员工，将其加入其直接负责人的下属列表
    for (let i = 0; i < n; i++) {
        if (!g.has(manager[i])) {
            g.set(manager[i], []);
        }
        g.get(manager[i]).push(i);
    }

    // 从总负责人开始遍历整棵树，并计算总通知时间
    return dfs(headID, informTime, g);
}




var numOfMinutes = function (n, headID, manager, informTime) {
    // 初始化哈希表
    const g = new Map();
    for (let i = 0; i < n; i++) {
        if (!g.has(manager[i])) {
            g.set(manager[i], []);
        }
        g.get(manager[i]).push(i);
    }
    // 初始化队列
    const queue = [];
    queue.push([headID, 0]);

    // 初始化结果
    let res = 0;

    // BFS
    while (queue.length) {
        const arr = queue.shift();
        const tmpId = arr[0], val = arr[1];
        if (!g.has(tmpId)) {
            // 如果当前节点没有下属，更新结果
            res = Math.max(res, val);
        } else {
            // 遍历当前节点的下属，将其加入队列
            for (const ne of g.get(tmpId)) {
                queue.push([ne, val + informTime[tmpId]]);
            }
        }
    }
    return res;
}



// 定义函数，输入为公司总人数 n，领导的 ID headID，每个员工的直接领导的 ID 数组 manager，员工被通知所需时间的数组 informTime
var numOfMinutes = function (n, headID, manager, informTime) {
    // 定义初始值为 0 的结果变量 res 和空 Map memo，用于存储已经计算过的员工所需时间
    let res = 0;
    const memo = new Map();
    // 定义 dfs 函数，参数为当前员工的 ID cur
    const dfs = (cur) => {
        // 若当前员工为领导，返回 0
        if (cur === headID) {
            return 0;
        }
        // 若 memo 中不存在当前员工的计算结果，进行 DFS 计算
        if (!memo.has(cur)) {
            const res = dfs(manager[cur]) + informTime[manager[cur]];
            // 将当前员工的计算结果存入 memo 中
            memo.set(cur, res);
        }
        // 返回 memo 中当前员工的计算结果
        return memo.get(cur);
    }
    // 遍历每个员工，计算其所需时间，并更新结果变量 res
    for (let i = 0; i < n; i++) {
        res = Math.max(res, dfs(i));
    }
    // 返回结果变量 res
    return res;
}