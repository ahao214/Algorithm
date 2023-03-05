using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6314. 统计可能的树根数目 

Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。

Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：

选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
Bob 猜测树中 u 是 v 的 父节点 。
Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。

Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。

给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0
     */
    public class Class6314
    {

        const int N = (int)1e5 + 1, M = N * 2;
        int[] h = new int[N], ne = new int[M], e = new int[M], w = new int[N];
        int[] son = new int[M], father = new int[M], ans = new int[M];
        int[] fa_son = new int[N];
        Dictionary<int, Dictionary<int, int>> d = new();
        int idx = 0;
        public int RootCount(int[][] edges, int[][] guesses, int k)
        {
            Array.Fill(h, -1);
            foreach (var g in guesses)
            {
                if (!d.ContainsKey(g[0]))
                    d[g[0]] = new Dictionary<int, int>();
                d[g[0]][g[1]] = 1;
            }
            foreach (var edge in edges)
            {
                int u = edge[0], v = edge[1];
                e[idx] = v; ne[idx] = h[u]; h[u] = idx++;
                e[idx] = u; ne[idx] = h[v]; h[v] = idx++;
            }
            Dfs1(0, -1);
            Dfs2(0, -1);
            Dfs3(0, -1);
            int cnt = 0;
            for (int i = 0; i <= edges.Length; i++)
            {
                if (ans[i] >= k)
                    cnt++;
            }
            return cnt;
        }

        public void Dfs1(int u, int fa)
        {
            for (int i = h[u]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (j == fa) continue;
                else Dfs1(j, u);
            }
            if (fa != -1) son[fa] += son[u] + (d.ContainsKey(fa) && d[fa].ContainsKey(u) ? 1 : 0);
        }

        public void Dfs2(int u, int fa)
        {
            father[u] += (fa == -1 ? 0 : father[fa]) + (d.ContainsKey(u) && d[u].ContainsKey(fa) ? 1 : 0);
            if (fa != -1) fa_son[u] += son[fa] - son[u] + fa_son[fa] - (d.ContainsKey(fa) && d[fa].ContainsKey(u) ? 1 : 0);
            for (int i = h[u]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (j == fa) continue;
                else Dfs2(j, u);
            }
        }

        public void Dfs3(int u, int fa)
        {
            ans[u] = (fa == -1 ? son[0] : son[u]) + father[u] + fa_son[u];
            for (int i = h[u]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (j == fa) continue;
                else Dfs3(j, u);
            }
        }

    }
}
