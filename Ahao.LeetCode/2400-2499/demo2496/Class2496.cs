using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2496
{
    public class Class2496
    {
        public int MaximumValue(string[] strs)
        {
            int res = 0;

            foreach (var s in strs)
            {
                bool isDigits = true;
                foreach (var ch in s)
                {
                    isDigits &= char.IsDigit(ch);
                }
                if (isDigits)
                {
                    res = Math.Max(res, Convert.ToInt32(s));
                }
                else
                {
                    res = Math.Max(res, s.Length);
                }

            }
            return res;

        }


    }
}
