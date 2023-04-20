using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1187
{
    public class Class1187
    {
        const int INF = 0x3f3f3f3f;

        public int MakeArrayIncreasing1(int[] arr1, int[] arr2)
        {
            Array.Sort(arr2);
            IList<int> list = new List<int>();
            int prev = -1;
            foreach (int num in arr2)
            {
                if (num != prev)
                {
                    list.Add(num);
                    prev = num;
                }
            }
            int n = arr1.Length;
            int m = list.Count;
            int[][] dp = new int[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new int[Math.Min(m, n) + 1];
                Array.Fill(dp[i], INF);
            }
            dp[0][0] = -1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= Math.Min(i, m); j++)
                {
                    /* 如果当前元素大于序列的最后一个元素 */
                    if (arr1[i - 1] > dp[i - 1][j])
                    {
                        dp[i][j] = arr1[i - 1];
                    }
                    if (j > 0 && dp[i - 1][j - 1] != INF)
                    {
                        /* 查找严格大于 dp[i - 1][j - 1] 的最小元素 */
                        int idx = BinarySearch1(list, j - 1, dp[i - 1][j - 1]);
                        if (idx != list.Count)
                        {
                            dp[i][j] = Math.Min(dp[i][j], list[idx]);
                        }
                    }
                    if (i == n && dp[i][j] != INF)
                    {
                        return j;
                    }
                }
            }
            return -1;
        }

        public int BinarySearch1(IList<int> list, int low, int target)
        {
            int high = list.Count;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (list[mid] > target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return low;
        }






    }
}
