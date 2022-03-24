using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1688
{
    public class Class1688
    {
        public int NumberOfMatches(int n)
        {
            int count = 0;
            while (n > 1)
            {
                if (n % 2 == 0)
                {
                    count += n / 2;
                    n = n / 2;
                }
                else
                {
                    count += (n - 1) / 2;
                    n = (n - 1) / 2 + 1;
                }
            }
            return count;
        }
    }
}
