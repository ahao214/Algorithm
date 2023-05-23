using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1090
{
    public class Class1090
    {

        public int LargestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit)
        {
            int n = values.Length;
            int[] id = new int[n];
            for (int i = 0; i < n; i++)
            {
                id[i] = i;
            }
            Array.Sort(id, (a, b) => values[b] - values[a]);

            int ans = 0, choose = 0;
            IDictionary<int, int> cnt = new Dictionary<int, int>();
            for (int i = 0; i < n && choose < numWanted; ++i)
            {
                int label = labels[id[i]];
                if (cnt.ContainsKey(label) && cnt[label] == useLimit)
                {
                    continue;
                }
                ++choose;
                ans += values[id[i]];
                cnt.TryAdd(label, 0);
                ++cnt[label];
            }
            return ans;
        }
    }
}
