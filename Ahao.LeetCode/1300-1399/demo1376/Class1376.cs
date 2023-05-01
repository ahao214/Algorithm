using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1376
{
    public class Class1376
    {

        public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime)
        {
            // 使用 Dictionary 来构建图
            IDictionary<int, IList<int>> g = new Dictionary<int, IList<int>>();
            for (int i = 0; i < n; i++)
            {
                g.TryAdd(manager[i], new List<int>());
                g[manager[i]].Add(i);
            }
            // 从根节点开始进行 DFS 并返回总时间
            return DFS(headID, informTime, g);
        }

        public int DFS(int cur, int[] informTime, IDictionary<int, IList<int>> g)
        {
            int res = 0;
            if (g.ContainsKey(cur))
            {
                // 遍历当前节点的邻居节点
                foreach (int neighbor in g[cur])
                {
                    res = Math.Max(res, DFS(neighbor, informTime, g));
                }
            }
            // 返回当前节点被通知需要的时间以及所有邻居节点被通知所需的最大时间
            return informTime[cur] + res;
        }


    }
}
