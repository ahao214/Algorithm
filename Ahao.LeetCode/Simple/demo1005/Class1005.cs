using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /// <summary>
    /// 1005. K 次取反后最大化的数组和
    /// </summary>
    public class Class1005
    {
        public int LargestSumAfterKNegations(int[] nums, int k)
        {
            int n = nums.Length;

            //根据数值的绝对值排序
            Array.Sort(nums, (x, y) =>
            {
                return Math.Abs(x) - Math.Abs(y);
            });
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] < 0 && k > 0)
                {
                    nums[i] = -1 * nums[i];
                    k--;
                }
            }
            if (k % 2 == 1)
            {
                nums[0] = -1 * nums[0];
            }
            return nums.Sum();
        }

        public int LargestSumAfterKNegations2(int[] nums, int k)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var num in nums)
            {
                if (!dic.ContainsKey(num))
                {
                    dic.Add(num, 0);
                }
                dic[num] += 1;
            }

            int res = nums.Sum();
            for (int i = -100; i < 0; i++)
            {
                if (dic.ContainsKey(i))
                {
                    int ops = Math.Min(k, dic[i]);
                    res += (-i) * ops * 2;
                    dic[i] -= ops;
                    if (!dic.ContainsKey(-i))
                    {
                        dic.Add(-i, 0);
                    }
                    dic[-i] += ops;
                    k -= ops;
                    if (k == 0)
                    {
                        break;
                    }
                }
            }
            if (k > 0 && k % 2 == 1 && !dic.ContainsKey(0))
            {
                for (int i = 1; i <= 100; i++)
                {
                    if (dic.ContainsKey(i))
                    {
                        res -= i * 2;
                        break;
                    }
                }
            }
            return res;
        }
    }
}
