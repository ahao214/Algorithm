using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1003
{
    public class Class1003
    {
        public bool IsValid(string s)
        {
            while (s.Contains("abc"))
            {
                s = s.Replace("abc", "");
            }

            return s.Length == 0;
        }



        public bool IsValid2(string s)
        {
            StringBuilder stk = new StringBuilder();
            foreach (char c in s)
            {
                stk.Append(c);
                if (stk.Length >= 3 && stk.ToString().Substring(stk.Length - 3).Equals("abc"))
                {
                    stk.Remove(stk.Length - 3, 3);
                }
            }
            return stk.Length == 0;
        }

    }
}
