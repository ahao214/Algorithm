#include<vector>
#include<unordered_set>


using namespace std;



/*
2581. 统计可能的树根数目

Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。

Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：

选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
Bob 猜测树中 u 是 v 的 父节点 。
Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。

Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。

给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。
*/
class Solution {
    vector<int> next[100005];
    unordered_set<int> guess[100005];
    int k;
    int ret = 0;
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        int n = edges.size() + 1;
        for (auto& e : edges)
        {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for (auto& g : guesses)
            guess[g[0]].insert(g[1]);

        int count = dfs(0, -1);

        dfs2(0, -1, count);

        return ret;
    }

    int dfs(int cur, int parent)
    {
        int count = 0;
        for (int nxt : next[cur])
        {
            if (nxt == parent) continue;
            count += dfs(nxt, cur);
            if (guess[cur].find(nxt) != guess[cur].end())
                count += 1;
        }
        return count;
    }

    void dfs2(int cur, int parent, int count)
    {
        if (count >= k) ret++;
        for (int nxt : next[cur])
        {
            if (nxt == parent) continue;
            int temp = count;
            if (guess[cur].find(nxt) != guess[cur].end())
                temp -= 1;
            if (guess[nxt].find(cur) != guess[nxt].end())
                temp += 1;
            dfs2(nxt, cur, temp);
        }
    }
};