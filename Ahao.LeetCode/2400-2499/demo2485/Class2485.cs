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


        public int PivotInteger2(int n)
        {
            int t = (n * n + n) / 2;
            int x = (int)Math.Sqrt(t);
            if (x * x == t)
            {
                return x;
            }
            return -1;
        }

        public int PivotInteger3(int n)
        {
            int sum = (n) * (n + 1) / 2;
            int pre = 1;
            for (int i = 1; i <= n; i++)
            {
                if (pre == sum) return i;
                pre += i + 1;
                sum -= i;
            }
            return -1;
        }

    }
}
