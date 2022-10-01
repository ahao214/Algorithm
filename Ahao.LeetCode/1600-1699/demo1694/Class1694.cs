﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1694
{
    public class Class1694
    {
        public string ReformatNumber(string number)
        {
            StringBuilder sb = new StringBuilder();
            foreach (char ch in number)
            {
                if (char.IsDigit(ch))
                {
                    sb.Append(ch);
                }
            }

            string digits = sb.ToString();
            int n = digits.Length;
            int pt = 0;
            StringBuilder ans = new StringBuilder();
            while (n > 0)
            {
                if (n > 4)
                {
                    ans.Append(digits.Substring(pt, 3) + "-");
                    pt += 3;
                    n -= 3;
                }
                else
                {
                    if (n == 4)
                    {
                        ans.Append(digits.Substring(pt, 2) + "-" + digits.Substring(pt + 2, 2));
                    }
                    else
                    {
                        ans.Append(digits.Substring(pt, n));
                    }
                    break;
                }
            }
            return ans.ToString();
        }
    }
}
