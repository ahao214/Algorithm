using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.LC594
{
    /// <summary>
    /// 594. 最长和谐子序列
    /// </summary>
    public class Class594
    {
        /// <summary>
        /// 枚举方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int FindLHS(int[] nums)
        {
            Array.Sort(nums);
            int begin = 0;
            int res = 0;
            for (int end = 0; end < nums.Length; end++)
            {
                while (nums[end] - nums[begin] > 1)
                {
                    begin++;
                }
                if (nums[end] - nums[begin] == 1)
                {
                    res = Math.Max(res, end - begin + 1);
                }
            }
            return res;
        }

        /// <summary>
        /// 哈希表方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int FindLHS2(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int result = 0;
            foreach (int num in nums)
            {
                if (dic.ContainsKey(num))
                {
                    dic[num]++;
                }
                else
                {
                    dic.Add(num, 1);
                }
            }

            foreach (int key in dic.Keys)
            {
                if (dic.ContainsKey(key + 1))
                {
                    result = Math.Max(result, dic[key] + dic[key + 1]);
                }
            }
            return result;
        }
    }
}
