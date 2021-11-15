using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 453. 最小操作次数使数组元素相等
    /// </summary>
    public class MinMoves
    {
        /// <summary>
        /// 每次操作使 n−1 个元素增加1，也可以理解使每个元素减少1
        /// 使每个元素减少1得到数组中最小的元素的步数
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int Method(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }
            int minValue = nums.Min();
            int res = 0;
            foreach (var num in nums)
            {
                res += num - minValue;
            }
            return res;
        }
    }
}
