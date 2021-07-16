using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer 53 - I. 在排序数组中查找数字 I
    /// </summary>
    public class Search
    {
        public int Method(int[] nums, int target)
        {
            int len = nums.Length;
            int result = 0;
            if (nums == null || len <= 0)
            {
                return result;
            }
            foreach (var item in nums)
            {
                if (item == target)
                {
                    result++;
                }
            }
            return result;
        }
    }
}
