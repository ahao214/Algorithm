using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 347.前K个高频元素
    /// </summary>
    public class TopKFrequent
    {
        public int[] Method(int[] nums, int k)
        {
            Array.Sort(nums);
            return nums.GroupBy(r => r).OrderByDescending(r=>r.Count()).Take(k).Select(r => r.Key).ToArray();
        }
    }
}
