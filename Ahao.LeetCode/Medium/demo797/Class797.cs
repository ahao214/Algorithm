using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo797
{
    /*
     797. 所有可能的路径
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
     */
    public class Class797
    {
        IList<IList<int>> res;
        public IList<IList<int>> AllPathsSourceTarget(int[][] graph)
        {
            res = new List<IList<int>>();
            IList<int> lst = new List<int>();
            int n = graph.Length;
            Dfs(graph, lst, 0, n);
            return res;
        }

        private void Dfs(int[][] graph, IList<int> lst, int x, int n)
        {
            lst.Add(x);
            if (x == n - 1)
            {
                res.Add(new List<int>(lst));
                return;
            }
            for (int i = 0; i < graph[x].Length; i++)
            {
                Dfs(graph, lst, graph[x][i], n);
                lst.RemoveAt(lst.Count - 1);
            }
        }
    }
}
