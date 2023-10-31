﻿var maximumInvitations = function (favorite) {
    const n = favorite.length;
    // 统计入度，便于进行拓扑排序
    const indeg = new Array(n).fill(0);
    for (x of favorite) {
        indeg[x]++;
    }

    const used = new Array(n).fill(false)
    const f = new Array(n).fill(1)
    const q = []
    for (let i = 0; i < n; i++) {
        if (!indeg[i]) {
            q.push(i);
        }
    }
    while (q.length) {
        let u = q.pop();
        used[u] = true;
        let v = favorite[u];
        // 状态转移
        f[v] = Math.max(f[v], f[u] + 1);
        indeg[v]--;
        if (!indeg[v]) {
            q.unshift(v);
        }
    }
    // ring 表示最大的环的大小
    // total 表示所有环大小为 2 的「基环内向树」上的最长的「双向游走」路径之和
    let ring = 0, total = 0;
    for (let i = 0; i < n; i++) {
        if (!used[i]) {
            let j = favorite[i];
            // favorite[favorite[i]] = i 说明环的大小为 2
            if (favorite[j] == i) {
                total += f[i] + f[j]
                used[i] = used[j] = true;
            } else {
                // 否则环的大小至少为 3，我们需要找出环
                let u = i, cnt = 0;
                while (true) {
                    cnt++;
                    u = favorite[u];
                    used[u] = true;
                    if (u == i) {
                        break;
                    }
                }
                ring = Math.max(ring, cnt);
            }
        }
    }
    return Math.max(ring, total);
};
