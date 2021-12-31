using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo507
{
    /// <summary>
    /// 507. 完美数
    /// </summary>
    public class Class507
    {
        public bool CheckPerfectNumber(int num)
        {
            int sum = 0;
            for (int i = 1; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    sum += i;
                }
            }
            return sum == num;
        }


        public bool CheckPerfectNumber1(int num)
        {
            if (num == 1)
            {
                return false;
            }

            int sum = 1;
            for (int d = 2; d * d <= num; ++d)
            {
                if (num % d == 0)
                {
                    sum += d;
                    if (d * d < num)
                    {
                        sum += num / d;
                    }
                }
            }
            return sum == num;
        }
    }
}
