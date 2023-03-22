using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1626
{
    public class Class1626
    {
        public int BestTeamScore(int[] scores, int[] ages)
        {
            int n = scores.Length;
            int[][] people = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                people[i] = new int[] { scores[i], ages[i] };
            }
            Array.Sort(people, (a, b) => a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
            int[] dp = new int[n];
            int res = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (people[j][1] <= people[i][1])
                    {
                        dp[i] = Math.Max(dp[i], dp[j]);
                    }
                }
                dp[i] += people[i][0];
                res = Math.Max(res, dp[i]);
            }
            return res;
        }


        int maxAge;
        int[] t;
        int[][] people;

        public int BestTeamScore2(int[] scores, int[] ages)
        {
            maxAge = ages.Max();
            t = new int[maxAge + 1];
            int res = 0;
            int n = scores.Length;
            people = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                people[i] = new int[] { scores[i], ages[i] };
            }
            Array.Sort(people, (a, b) => a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);

            for (int i = 0; i < n; ++i)
            {
                int score = people[i][0], age = people[i][1], cur = score + Query(age);
                Update(age, cur);
                res = Math.Max(res, cur);
            }
            return res;
        }

        public int lowbit(int x)
        {
            return x & (-x);
        }

        public void Update(int i, int val)
        {
            for (; i <= maxAge; i += lowbit(i))
            {
                t[i] = Math.Max(t[i], val);
            }
        }

        public int Query(int i)
        {
            int ret = 0;
            for (; i > 0; i -= lowbit(i))
            {
                ret = Math.Max(ret, t[i]);
            }
            return ret;
        }


    }
}
