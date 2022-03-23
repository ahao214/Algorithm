using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1342
{
    public class Class1342
    {
        public int NumberOfSteps(int num)
        {
            int res = 0;
            while (num != 0)
            {
                if (num % 2 == 0)
                {
                    num /= 2;
                    res++;
                }
                else
                {
                    num -= 1;
                    res++;
                }
            }
            return res;
        }

        public int NumberOfSteps1(int num)
        {
            int ret = 0;
            while (num > 0)
            {
                ret += (num > 1 ? 1 : 0) + (num & 0x01);
                num >>= 1;
            }
            return ret;
        }
    }
}
