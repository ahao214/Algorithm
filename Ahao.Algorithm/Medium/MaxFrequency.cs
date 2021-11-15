using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1838. 最高频元素的频数
    /// </summary>
    public class MaxFrequency
    {
        public int Method(int[] nums, int k)
        {
            int tempK = k;
            int result = 1;
            Array.Sort(nums);
            int len = nums.Length;
            int tmp = 1;
            for (int i = len - 1; i >= 0; i--)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[i] - nums[j] <= k)
                    {
                        tmp++;
                        k = k - (nums[i] - nums[j]);
                    }
                }
                result = Math.Max(result, tmp);
                tmp = 1;
                k = tempK;
            }

            return result;
        }

        public int Method2(int[] nums, int k)
        {
            Array.Sort(nums);
            int n = nums.Length;
            long total = 0;
            int l = 0, res = 1;
            for (int r = 1; r < n; ++r)
            {
                total += (long)(nums[r] - nums[r - 1]) * (r - l);
                while (total > k)
                {
                    total -= nums[r] - nums[l];
                    ++l;
                }
                res = Math.Max(res, r - l + 1);
            }
            return res;
        }
    }
}
