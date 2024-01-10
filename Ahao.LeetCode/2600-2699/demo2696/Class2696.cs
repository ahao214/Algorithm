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



        public int MinLength2(string s)
        {
            IList<char> stack = new List<char>();
            foreach (char c in s)
            {
                stack.Add(c);
                int m = stack.Count;
                if (m >= 2 &&
                    (stack[m - 2] == 'A' && stack[m - 1] == 'B' ||
                    stack[m - 2] == 'C' && stack[m - 1] == 'D'))
                {
                    stack.RemoveAt(m - 1);
                    stack.RemoveAt(m - 2);
                }
            }
            return stack.Count;
        }


    }
}
