using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2049
{
    /*
     2049. 统计最高分的节点数目
给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents 表示这棵树，其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。

一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。

请你返回有 最高得分 节点的 数目 。
     */
    public class Class2049
    {
        long maxScore = 0;
        int cnt = 0;
        int n;
        IList<int>[] children;

        public int CountHighestScoreNodes(int[] parents)
        {
            n = parents.Length;
            children = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                children[i] = new List<int>();
            }
            for (int i = 0; i < n; i++)
            {
                int p = parents[i];
                if (p != -1)
                {
                    children[p].Add(i);
                }
            }
            DFS(0);
            return cnt;
        }

        public int DFS(int node)
        {
            long score = 1;
            int size = n - 1;
            foreach (int c in children[node])
            {
                int t = DFS(c);
                score *= t;
                size -= t;
            }
            if (node != 0)
            {
                score *= size;
            }
            if (score == maxScore)
            {
                cnt++;
            }
            else if (score > maxScore)
            {
                maxScore = score;
                cnt = 1;
            }
            return n - size;
        }
    }
}
