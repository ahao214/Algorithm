using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1780
{
    public class Class1780
    {
        public bool CheckPowersOfThree(int n)
        {
            while (n != 0)
            {
                if (n % 3 == 2)
                {
                    return false;
                }
                n /= 3;
            }
            return true;
        }
    }
}
