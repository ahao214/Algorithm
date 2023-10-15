using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo137
{

    public class Class137
    {


        public int SingleNumber(int[] nums)
        {
            int ans = 0;
            for (int i = 0; i < 32; ++i)
            {
                int total = 0;

                foreach (var num in nums)
                {
                    total += ((num >> i) & 1);
                }
                if (total % 3 != 0)
                {
                    ans |= (1 << i);
                }
            }
            return ans;
        }



    }
}
