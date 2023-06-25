using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2485
{
    public class Class2485
    {

        public int PivotInteger(int n)
        {
            int res = -1;

            for (int i = 1; i <= n; i++)
            {
                int leftSum = i * (i + 1) / 2;
                int rightSum = (n - i + 1) * (i + n) / 2;
                if (leftSum == rightSum)
                {
                    return i;
                }
            }

            return res;
        }


    }
}
