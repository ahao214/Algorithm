using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1796
{
    public class Class1796
    {

        public int SecondHighest(string s)
        {
            int first = -1, second = -1;
            foreach (char c in s)
            {
                if (char.IsDigit(c))
                {
                    int num = c - '0';
                    if (num > first)
                    {
                        second = first;
                        first = num;
                    }
                    else if (num < first && num > second)
                    {
                        second = num;
                    }
                }
            }
            return second;
        }
    }
}
