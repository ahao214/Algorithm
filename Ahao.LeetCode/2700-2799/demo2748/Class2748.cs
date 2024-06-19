using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2748
{
    internal class Class2748
    {
        public int CountBeautifulPairs(int[] nums)
        {
            int res = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                while (nums[i] >= 10)
                {
                    nums[i] /= 10;
                }
                for (int j = i + 1; j < n; j++)
                {
                    if (GCD(nums[i], nums[j] % 10) == 1)
                    {
                        res++;
                    }
                }
            }
            return res;
        }

        private int GCD(int x, int y)
        {
            return y == 0 ? x : GCD(y, x % y);
        }



        public int CountBeautifulPairs2(int[] nums)
        {
            int res = 0;
            int[] cnt = new int[10];
            foreach (int x in nums)
            {
                for (int y = 1; y <= 9; y++)
                {
                    if (GCD(x % 10, y) == 1)
                    {
                        res += cnt[y];
                    }
                }
                int x2 = x;
                while (x2 >= 10)
                {
                    x2 /= 10;
                }
            }
            return res;

        }

    }
}
