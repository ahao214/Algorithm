using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 414. 第三大的数
    /// </summary>
    public class ThirdMax
    {
        public int Method(int[] nums)
        {
            SortedSet<int> set = new SortedSet<int>();
            foreach (var num in nums)
            {
                set.Add(num);
                if (set.Count > 3)
                {
                    set.Remove(set.Min);
                }
            }
            if (set.Count == 3)
            {
                return set.Min;
            }
            else
            {
                return set.Max;
            }
        }
    }
}
