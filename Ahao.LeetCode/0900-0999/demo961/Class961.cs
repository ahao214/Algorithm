using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo961
{
    public class Class961
    {
        public int RepeatedNTimes(int[] nums)
        {
            ISet<int> res = new HashSet<int>();
            foreach (var num in nums)
            {
                if (!res.Add(num))
                    return num;
            }
            return -1;
        }
    }
}
