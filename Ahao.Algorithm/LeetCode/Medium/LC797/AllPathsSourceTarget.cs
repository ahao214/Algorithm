using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC797
{
    /// <summary>
    /// 797. 所有可能的路径
    /// </summary>
    public class AllPathsSourceTarget
    {
        IList<IList<int>> res;
        public IList<IList<int>> Method(int[][] graph)
        {
            res = new List<IList<int>>();
            IList<int> lst = new List<int>();
            int n = graph.Length;
            Dfs(graph, lst, 0, n);
            return res;
        }

        public void Dfs(int[][] graph, IList<int> lst, int x, int n)
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
