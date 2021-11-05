using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple.LC268
{
    /// <summary>
    /// 268. 丢失的数字
    /// </summary>
    public class Class268
    {
        /// <summary>
        /// 排序方法
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MissingNumber(int[] nums)
        {
            Array.Sort(nums);
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] != i)
                    return i;
            }
            return n;
        }

        /// <summary>
        /// 哈希集合
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MissingNumber2(int[] nums)
        {
            ISet<int> set = new HashSet<int>();
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                set.Add(nums[i]);
            }
            int missing = -1;
            for (int i = 0; i <= n; i++)
            {
                if (!set.Contains(i))
                {
                    missing = i;
                    break;
                }
            }
            return missing;
        }


        /// <summary>
        /// 位运算
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MissingNumber3(int[] nums)
        {
            int xor = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                xor ^= nums[i];
            }
            for (int i = 0; i <= n; i++)
            {
                xor ^= i;
            }
            return xor;
        }

    }
}
