using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo851
{
    /// <summary>
    /// 851. 喧闹和富有
    /// </summary>
    public class Class851
    {
        //深度优先
        public int[] LoudAndRich(int[][] richer, int[] quiet)
        {
            int n = quiet.Length;
            IList<int>[] g = new List<int>[n];
            for (int i = 0; i < n; ++i)
            {
                g[i] = new List<int>();
            }
            foreach (int[] r in richer)
            {
                g[r[1]].Add(r[0]);
            }

            int[] ans = new int[n];
            Array.Fill(ans, -1);
            for (int i = 0; i < n; ++i)
            {
                DFS(i, quiet, g, ans);
            }
            return ans;
        }
        public void DFS(int x, int[] quiet, IList<int>[] g, int[] ans)
        {
            if (ans[x] != -1)
            {
                return;
            }
            ans[x] = x;
            foreach (int y in g[x])
            {
                DFS(y, quiet, g, ans);
                if (quiet[ans[y]] < quiet[ans[x]])
                {
                    ans[x] = ans[y];
                }
            }
        }



        //拓扑排序
        public int[] LoudAndRich1(int[][] richer, int[] quiet)
        {
            int n = quiet.Length;
            IList<int>[] g = new List<int>[n];
            for (int i = 0; i < n; ++i)
            {
                g[i] = new List<int>();
            }
            int[] inDeg = new int[n];
            foreach (int[] r in richer)
            {
                g[r[0]].Add(r[1]);
                ++inDeg[r[1]];
            }

            int[] ans = new int[n];
            for (int i = 0; i < n; ++i)
            {
                ans[i] = i;
            }
            Queue<int> q = new Queue<int>();
            for (int i = 0; i < n; ++i)
            {
                if (inDeg[i] == 0)
                {
                    q.Enqueue(i);
                }
            }
            while (q.Count > 0)
            {
                int x = q.Dequeue();
                foreach (int y in g[x])
                {
                    if (quiet[ans[x]] < quiet[ans[y]])
                    {
                        ans[y] = ans[x]; // 更新 x 的邻居的答案
                    }
                    if (--inDeg[y] == 0)
                    {
                        q.Enqueue(y);
                    }
                }
            }
            return ans;
        }

    }
}
