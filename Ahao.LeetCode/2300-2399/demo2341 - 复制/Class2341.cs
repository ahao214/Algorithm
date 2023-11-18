using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2342
{
    public class Class2342
    {
        public int MaximumSum(int[] nums)
        {
            int n = nums.Length;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int result = -1;
            for (int i = 0; i < n; i++)
            {
                int cur = 0;
                cur = SumBits(nums[i]);
                if (!dic.ContainsKey(cur))
                {
                    dic.Add(cur, nums[i]);
                }
                else
                {
                    result = Math.Max(result, dic[cur] + nums[i]);
                    if (dic[cur] < nums[i])
                    {
                        dic[cur] = nums[i];
                    }
                }
            }
            return result;
        }

        public int SumBits(int n)
        {
            int result = 0;
            while (n > 0)
            {
                result += n % 10;
                n /= 10;
            }
            return result;
        }





    }
}
