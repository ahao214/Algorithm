#include<vector>

using namespace std;



/*
2646. 最小化旅行的价格总和

现有一棵无向、无根的树，树中有 n 个节点，按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。

每个节点都关联一个价格。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价格。

给定路径的 价格总和 是该路径上所有节点的价格之和。

另给你一个二维整数数组 trips ，其中 trips[i] = [starti, endi] 表示您从节点 starti 开始第 i 次旅行，并通过任何你喜欢的路径前往节点 endi 。

在执行第一次旅行之前，你可以选择一些 非相邻节点 并将价格减半。

返回执行所有旅行的最小价格总和。
*/
class Solution {
    vector<int>next[55];
    int n;
    int count[55];
    int plan0[55];
    int plan1[55];
    int val[55];
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips)
    {
        for (auto& edge : edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
            plan0[i] = -1;
            plan1[i] = -1;
        }

        for (auto& trip : trips)
        {
            dfs(trip[0], -1, trip[1]);
        }

        for (int i = 0; i < n; i++)
        {
            val[i] = price[i] * count[i];
        }

        return DFS(0, -1, 1);
    }

    bool dfs(int cur, int parent, int target)
    {
        if (cur == target)
        {
            count[cur]++;
            return true;
        }

        for (int x : next[cur])
        {
            if (x == parent) continue;
            if (dfs(x, cur, target))
            {
                count[cur]++;
                return true;
            }
        }
        return false;
    }

    int DFS(int node, int parent, int flag)  // flag = 1 : can choose;  flag = 0 : cannot choose 
    {
        if (flag == 0 && plan0[node] != -1) return plan0[node];
        if (flag == 1 && plan1[node] != -1) return plan1[node];

        if (flag == 0)
        {
            int ret = val[node];
            for (int x : next[node])
            {
                if (x == parent) continue;
                ret += DFS(x, node, 1);
            }
            plan0[node] = ret;
            return ret;
        }
        else
        {
            int ret = INT_MAX;
            int option1 = val[node] / 2;
            for (int x : next[node])
            {
                if (x == parent) continue;
                option1 += DFS(x, node, 0);
            }

            int option2 = val[node];
            for (int x : next[node])
            {
                if (x == parent) continue;
                option2 += DFS(x, node, 1);
            }

            ret = min(option1, option2);
            plan1[node] = ret;
            return ret;
        }
    }
};
