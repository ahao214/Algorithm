using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo754
{
    public class Class754
    {
        public int ReachNumber(int target)
        {
            target = Math.Abs(target);
            int k = 0;
            while (target > 0)
            {
                k++;
                target -= k;
            }
            return target % 2 == 0 ? k : k + 1 + k % 2;
        }
    }
}
