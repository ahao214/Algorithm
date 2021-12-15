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
    }
}
