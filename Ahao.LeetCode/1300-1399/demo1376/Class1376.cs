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




        public int NumOfMinutes2(int n, int headID, int[] manager, int[] informTime)
        {
            IDictionary<int, IList<int>> g = new Dictionary<int, IList<int>>();
            // 构建邻接表
            for (int i = 0; i < n; i++)
            {
                g.TryAdd(manager[i], new List<int>());
                g[manager[i]].Add(i);
            }
            Queue<int[]> queue = new Queue<int[]>();
            // 将起点放入队列
            queue.Enqueue(new int[] { headID, 0 });
            int res = 0;
            while (queue.Count > 0)
            {
                int[] arr = queue.Dequeue();
                int tmpId = arr[0], val = arr[1];
                // 如果当前节点没有下属，说明到达了叶子节点，更新结果
                if (!g.ContainsKey(tmpId))
                {
                    res = Math.Max(res, val);
                }
                else
                {
                    // 将当前节点的下属加入队列，更新时间
                    foreach (int ne in g[tmpId])
                    {
                        queue.Enqueue(new int[] { ne, val + informTime[tmpId] });
                    }
                }
            }
            return res;
        }





        int headID;
        int[] manager;
        int[] informTime;
        IDictionary<int, int> memo = new Dictionary<int, int>();

        public int NumOfMinutes3(int n, int headID, int[] manager, int[] informTime)
        {
            this.headID = headID;
            this.manager = manager;
            this.informTime = informTime;
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                res = Math.Max(res, DFS(i));
            }
            return res;
        }

        public int DFS(int cur)
        {
            if (cur == headID)
            {
                return 0;
            }
            if (!memo.ContainsKey(cur))
            {
                int res = DFS(manager[cur]) + informTime[manager[cur]];
                memo.Add(cur, res);
            }
            return memo[cur];
        }



    }
}
