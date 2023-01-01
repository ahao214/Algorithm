using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099.demo6278
{
    public class Class6278
    {
        public int CountDigits(int num)
        {
            int res = 0;
            int oldNum = num;
            while (num != 0)
            {
                if (oldNum % (num % 10) == 0)
                {
                    res++;
                }
                num /= 10;
            }
            return res;
        }
    }
}
