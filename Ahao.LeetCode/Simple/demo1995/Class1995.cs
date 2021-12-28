using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1995
{
    /// <summary>
    /// 1995. 统计特殊四元组
    /// </summary>
    public class Class1995
    {
        public int CountQuadruplets(int[] nums)
        {
            int n = nums.Length;
            int res = 0;
            for (int a = 0; a < n; a++)
            {
                for (int b = a + 1; b < n; b++)
                {
                    for (int c = b + 1; c < n; c++)
                    {
                        for (int d = c + 1; d < n; d++)
                        {
                            if (nums[a] + nums[b] + nums[c] == nums[d])
                            {
                                res++;
                            }
                        }
                    }
                }
            }
            return res;
        }


        //使用哈希表存储nums[d]
        public int CountQuadruplets1(int[] nums)
        {
            int n = nums.Length;
            int res = 0;
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            for (int c = n - 2; c >= 2; --c)
            {
                if (!cnt.ContainsKey(nums[c + 1]))
                {
                    cnt.Add(nums[c + 1], 1);
                }
                else
                {
                    ++cnt[nums[c + 1]];
                }
                for (int a = 0; a < c; ++a)
                {
                    for (int b = a + 1; b < c; ++b)
                    {
                        int sum = nums[a] + nums[b] + nums[c];
                        if (cnt.ContainsKey(sum))
                        {
                            res += cnt[sum];
                        }
                    }
                }
            }
            return res;
        }


    }
}
