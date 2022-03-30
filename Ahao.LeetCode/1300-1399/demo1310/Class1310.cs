using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399
{
    public class Class1310
    {
        public int[] XorQueries(int[] arr, int[][] queries)
        {
            int n = arr.Length;
            int[] xors = new int[n + 1];
            for (int i = 0; i < n; i++)
                xors[i + 1] = xors[i] ^ arr[i];
            int m = queries.Length;
            int[] ans = new int[m];
            for (int i = 0; i < m; i++)
            {
                ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
            }
            return ans;
        }
    }
}
