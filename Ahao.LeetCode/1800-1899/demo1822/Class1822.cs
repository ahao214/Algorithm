using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1822
{
    public class Class1822
    {
        public int ArraySign(int[] nums)
        {
            int sign = 1;
            foreach (int num in nums)
            {
                if (num == 0)
                {
                    return 0;
                }
                if (num < 0)
                {
                    sign = -sign;
                }
            }
            return sign;
        }
    }
}
