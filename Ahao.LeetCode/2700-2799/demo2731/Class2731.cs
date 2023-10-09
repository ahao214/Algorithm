using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2731
{
    internal class Class2731
    {

        const int MOD = 1000000007;

        public int SumDistance(int[] nums, string s, int d)
        {
            int n = nums.Length;
            long[] pos = new long[n];
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'L')
                {
                    pos[i] = (long)nums[i] - d;
                }
                else
                {
                    pos[i] = (long)nums[i] + d;
                }
            }
            Array.Sort(pos);
            long res = 0;
            for (int i = 1; i < n; i++)
            {
                res += 1L * (pos[i] - pos[i - 1]) * i % MOD * (n - i) % MOD;
                res %= MOD;
            }
            return (int)res;
        }



        public int SumDistance2(int[] nums, String s, int d)
        {
            long MOD = (long)1e9 + 7;
            int n = nums.Length;
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = (long)nums[i] + (s[i] == 'L' ? -d : d);
            }

            Array.Sort(a);
            long ans = 0, sum = 0;
            for (int i = 0; i < n; i++)
            {
                ans = (ans + i * a[i] - sum) % MOD;
                sum += a[i];
            }
            return (int)ans;
        }


    }
}
