using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2006
{
    /*
     2006. 差的绝对值为 K 的数对数目
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
     */
    public class Class2006
    {
        public int CountKDifference(int[] nums, int k)
        {
            int res = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (Math.Abs(nums[i] - nums[j]) == k)
                    {
                        res++;
                    }
                }
            }
            return res;
        }


        public int CountKDifference1(int[] nums, int k)
        {
            int res = 0, n = nums.Length;
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            for (int j = 0; j < n; ++j)
            {
                res += (cnt.ContainsKey(nums[j] - k) ? cnt[nums[j] - k] : 0) + (cnt.ContainsKey(nums[j] + k) ? cnt[nums[j] + k] : 0);
                if (!cnt.ContainsKey(nums[j]))
                {
                    cnt.Add(nums[j], 0);
                }
                ++cnt[nums[j]];
            }
            return res;
        }
    }
}
