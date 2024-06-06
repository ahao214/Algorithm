using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999.demo2938
{
    internal class Class2938
    {
        public long MinimumSteps(string s)
        {
            long res = 0;
            int sum = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '1')
                {
                    sum++;
                }
                else
                {
                    res += sum;
                }
            }
            return res;
        }
    }
}
