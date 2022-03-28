using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2006
{    
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
