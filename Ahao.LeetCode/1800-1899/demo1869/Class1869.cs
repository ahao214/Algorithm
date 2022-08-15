using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1869
{
    public class Class1869
    {
        public bool CheckZeroOnes(string s)
        {
            int one = 0;
            int zero = 0;
            int s1 = 0;
            int s0 = 0;
            foreach (var c in s)
            {
                if (c == '0')
                {
                    s0++;
                    s1 = 0;
                }
                else
                {
                    s1++;
                    s0 = 0;
                }
                one = Math.Max(one, s1);
                zero = Math.Max(zero, s0);
            }
            return one > zero;
        }
    }
}
