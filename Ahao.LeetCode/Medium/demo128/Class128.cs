using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo128
{
    /// <summary>
    /// 128. 最长连续序列
    /// </summary>
    public class Class128
    {
        public int LongestConsecutive(int[] nums)
        {
            var set = new HashSet<int>(nums);
            var max = 0;
            foreach (var n in nums)
            {
                if (set.Contains(n - 1))
                {
                    continue;
                }
                var m = n + 1;
                while (set.Contains(m))
                {
                    m++;
                }
                max = Math.Max(max, m - n);
            }
            return max;
        }
    }
}
