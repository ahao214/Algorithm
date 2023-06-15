using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1494
{
    public class Class1494
    {

        public int MinNumberOfSemesters(int n, int[][] relations, int k)
        {
            int[] dp = new int[1 << n];
            Array.Fill(dp, int.MaxValue);
            int[] need = new int[1 << n];
            foreach (int[] edge in relations)
            {
                need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
            }
            dp[0] = 0;
            for (int i = 1; i < (1 << n); ++i)
            {
                need[i] = need[i & (i - 1)] | need[i & (-i)];
                if ((need[i] | i) != i)
                {
                    // i 中有任意一门课程的前置课程没有完成学习
                    continue;
                }
                int valid = i ^ need[i]; // 当前学期可以进行学习的课程集合

                if (NumberOfOne(valid) <= k)
                {
                    // 如果个数小于 k，则可以全部学习，不再枚举子集
                    dp[i] = Math.Min(dp[i], dp[i ^ valid] + 1);
                }
                else
                {
                    // 否则枚举当前学期需要进行学习的课程集合
                    for (int sub = valid; sub > 0; sub = (sub - 1) & valid)
                    {
                        if (NumberOfOne(sub) <= k)
                        {
                            dp[i] = Math.Min(dp[i], dp[i ^ sub] + 1);
                        }
                    }
                }
            }
            return dp[(1 << n) - 1];
        }

        public int NumberOfOne(int n)
        {
            int num = 0;
            int s = n;

            while (s != 0)
            {
                s &= (s - 1);
                num += 1;
            }
            return num;
        }


    }
}
