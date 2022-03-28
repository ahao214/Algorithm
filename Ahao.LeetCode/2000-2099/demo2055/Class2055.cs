using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2055
{
    public class Class2055
    {
        public int[] PlatesBetweenCandles(string s, int[][] queries)
        {
            int n = s.Length;
            int[] preSum = new int[n];
            for (int i = 0, sum = 0; i < n; i++)
            {
                if (s[i] == '*')
                {
                    sum++;
                }
                preSum[i] = sum;
            }
            int[] left = new int[n];
            for (int i = 0, le = -1; i < n; i++)
            {
                if (s[i] == '|')
                {
                    le = i;
                }
                left[i] = le;
            }
            int[] right = new int[n];
            for (int i = n - 1, ri = -1; i >= 0; i--)
            {
                if (s[i] == '|')
                {
                    ri = i;
                }
                right[i] = ri;
            }
            int[] ans = new int[queries.Length];
            for (int i = 0; i < queries.Length; i++)
            {
                int[] query = queries[i];
                int x = right[query[0]], y = left[query[1]];
                ans[i] = x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x];
            }
            return ans;
        }

    }
}
