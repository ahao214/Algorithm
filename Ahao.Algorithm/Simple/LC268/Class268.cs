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
            for(int i=0;i<n;i++)
            {
                if (nums[i] != i)
                    return i;
            }
            return n;
        }
    }
}
