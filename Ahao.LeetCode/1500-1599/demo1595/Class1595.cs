using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1595
{
    public class Class1595
    {
        public int ConnectTwoGroups(IList<IList<int>> cost)
        {
            int size1 = cost.Count, size2 = cost[0].Count, m = 1 << size2;
            int[][] dp = new int[size1 + 1][];
            for (int i = 0; i <= size1; i++)
            {
                dp[i] = new int[m];
                Array.Fill(dp[i], int.MaxValue / 2);
            }
            dp[0][0] = 0;
            for (int i = 1; i <= size1; i++)
            {
                for (int s = 0; s < m; s++)
                {
                    for (int k = 0; k < size2; k++)
                    {
                        if ((s & (1 << k)) == 0)
                        {
                            continue;
                        }
                        dp[i][s] = Math.Min(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
                        dp[i][s] = Math.Min(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
                        dp[i][s] = Math.Min(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
                    }
                }
            }
            return dp[size1][m - 1];
        }




        public int ConnectTwoGroups2(IList<IList<int>> cost)
        {
            int size1 = cost.Count, size2 = cost[0].Count, m = 1 << size2;
            int[] dp1 = new int[m];
            Array.Fill(dp1, int.MaxValue / 2);
            int[] dp2 = new int[m];
            dp1[0] = 0;
            for (int i = 1; i <= size1; i++)
            {
                for (int s = 0; s < m; s++)
                {
                    dp2[s] = int.MaxValue / 2;
                    for (int k = 0; k < size2; k++)
                    {
                        if ((s & (1 << k)) == 0)
                        {
                            continue;
                        }
                        dp2[s] = Math.Min(dp2[s], dp2[s ^ (1 << k)] + cost[i - 1][k]);
                        dp2[s] = Math.Min(dp2[s], dp1[s] + cost[i - 1][k]);
                        dp2[s] = Math.Min(dp2[s], dp1[s ^ (1 << k)] + cost[i - 1][k]);
                    }
                }
                Array.Copy(dp2, 0, dp1, 0, m);
            }
            return dp1[m - 1];
        }




        public int ConnectTwoGroups3(IList<IList<int>> cost)
        {
            // 矩阵的行数
            int n = cost.Count;
            // 矩阵的列数
            int m = cost[0].Count;
            // max为m对应压状的最大数字+1
            int max = 1 << m;
            // 矩阵每列的最小值
            int[] min = new int[m];

            // 使用滚动数组，取代二维数组dp[i][j]，i代表矩阵中第i行，j代表小于等于i行选择了哪些列对应的状压值
            int[] dp = new int[max];
            int[] dp2 = new int[max];
            // 初始化为最大值，便于调用Math.min方法时能刷新数据
            Array.Fill(dp, int.MaxValue);
            // 行号从1开始，第0行是虚拟行，表示还没有一行数据，此时压状值是0，对应的连通成本也是0
            dp[0] = 0;

            // 记录出矩阵每列的最小值            
            Array.Fill(min, int.MaxValue);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    min[j] = Math.Min(min[j], cost[i][j]);
                }
            }

            // 遍历矩阵每一行，从每行中选择一个数，并记录最终每个压状值的最小值
            for (int i = 0; i < n; i++)
            {
                Array.Fill(dp2, int.MaxValue);
                // 遍历每个压状值
                for (int j = 0; j < max; j++)
                {
                    // 如果当前状压值有效（即不是初始值），则通过此状压值计算下一行的值
                    if (dp[j] != int.MaxValue)
                    {
                        // 遍历这一行中的每个值，得到新的状压值得最小值
                        for (int k = 0; k < m; k++)
                        {
                            int next = j | 1 << k;
                            dp2[next] = Math.Min(dp2[next], dp[j] + cost[i][k]);
                        }
                    }
                }
                // 滚动交换数组
                int[] temp = dp;
                dp = dp2;
                dp2 = temp;
            }

            // 从每一行选出一个数后，遍历每个状压值，求出最终的最小值
            int ans = int.MaxValue;
            // 因为每行至少选择一个数，所以不能为0，遍历从1开始
            for (int i = 1; i < max; i++)
            {
                // 由于题意说明了行数大于列数，所以最后一行肯定包含了所有的状态，于是可以省去dp[j] != Integer.MAX_VALUE的判断
                int x = dp[i];
                // 遍历判断是否每一列都选上了，将未选择列的最小值加上
                for (int j = 0; j < m; j++)
                {
                    if ((i & 1 << j) == 0)
                    {
                        x += min[j];
                    }
                }
                ans = Math.Min(ans, x);
            }
            return ans;
        }


    }
}
