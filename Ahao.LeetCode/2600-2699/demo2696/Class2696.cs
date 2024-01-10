using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2696
{
    public class Class2696
    {
        public int MinLength(string s)
        {
            int length = 0;
            while (length != s.Length)
            {
                length = s.Length;
                s = s.Replace("AB", "").Replace("CD", "");
            }
            return length;
        }


    }
}
