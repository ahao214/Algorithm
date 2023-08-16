using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2682
{
    public class Class2682
    {
        public int[] CircularGameLosers(int n, int k)
        {
            bool[] visit = new bool[n];
            for (int i = k, j = 0; !visit[j]; i += k)
            {
                visit[j] = true;
                j = (j + i) % n;
            }
            IList<int> list = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (!visit[i])
                {
                    list.Add(i + 1);
                }
            }
            int[] ans = new int[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                ans[i] = list[i];
            }
            return ans;
        }


    }
}
