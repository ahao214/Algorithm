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

        public int LargestValsFromLabels2(int[] values, int[] labels, int numWanted, int useLimit)
        {
            int n = values.Length;
            int res = 0;
            int[][] grid = new int[n][];
            for (int i = 0; i < n; i++)
            {
                grid[i] = new int[2];
                grid[i][0] = values[i];
                grid[i][1] = labels[i];
            }

            Array.Sort(grid, (a, b) => b[0] - a[0]);
            IDictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < n && numWanted > 0; i++)
            {
                int value = grid[i][0], label = grid[i][1];
                dic.TryAdd(label, 0);
                int count = dic[label];
                if (count < useLimit)
                {
                    res += value;
                    dic[label]++;
                    numWanted--;
                }
            }
            return res;

        }
    }
}
