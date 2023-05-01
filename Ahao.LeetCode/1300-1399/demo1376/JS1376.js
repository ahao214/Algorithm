var numOfMinutes = function (n, headID, manager, informTime) {
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
