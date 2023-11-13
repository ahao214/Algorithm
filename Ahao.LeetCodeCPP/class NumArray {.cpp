#include<vector>
#include<string>

using namespace std;



/*
2858. 可以到达每一个节点的最少边反转次数

给你一个 n 个点的 简单有向图 （没有重复边的有向图），节点编号为 0 到 n - 1 。如果这些边是双向边，那么这个图形成一棵 树 。

给你一个整数 n 和一个 二维 整数数组 edges ，其中 edges[i] = [ui, vi] 表示从节点 ui 到节点 vi 有一条 有向边 。

边反转 指的是将一条边的方向反转，也就是说一条从节点 ui 到节点 vi 的边会变为一条从节点 vi 到节点 ui 的边。

对于范围 [0, n - 1] 中的每一个节点 i ，你的任务是分别 独立 计算 最少 需要多少次 边反转 ，从节点 i 出发经过 一系列有向边 ，可以到达所有的节点。

请你返回一个长度为 n 的整数数组 answer ，其中 answer[i]表示从节点 i 出发，可以到达所有节点的 最少边反转 次数。
*/
class Solution {
    vector<pair<int, int>> next[100005];
    vector<int>rets;
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges)
    {
        for (auto& edge : edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back({ b, 1 });
            next[b].push_back({ a, -1 });
        }

        int count = dfs1(0, -1);

        rets.resize(n);

        dfs2(0, -1, count);

        return rets;
    }

    int dfs1(int cur, int parent)
    {
        int ret = 0;
        for (auto& [nxt, dir] : next[cur])
        {
            if (nxt == parent) continue;
            if (dir == 1)
                ret += dfs1(nxt, cur);
            else
            {
                ret += dfs1(nxt, cur) + 1;
            }
        }
        return ret;
    }

    void dfs2(int cur, int parent, int count)
    {
        rets[cur] = count;
        for (auto& [nxt, dir] : next[cur])
        {
            if (nxt == parent) continue;
            if (dir == 1)
                dfs2(nxt, cur, count + 1);
            else
                dfs2(nxt, cur, count - 1);
        }
    }


};