using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1945
{
    public class Class1945
    {
        public int GetLucky(string s, int k)
        {
            StringBuilder sb = new StringBuilder();
            foreach (char ch in s)
            {
                sb.Append(ch - 'a' + 1);
            }
            string digits = sb.ToString();
            for (int i = 1; i <= k && digits.Length > 1; ++i)
            {
                int sum = 0;
                foreach (char ch in digits)
                {
                    sum += ch - '0';
                }
                digits = sum.ToString();
            }

            return int.Parse(digits);
        }
    }
}
