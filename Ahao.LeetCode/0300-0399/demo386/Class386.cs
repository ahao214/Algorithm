using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo386
{
    public class Class386
    {
        public IList<int> LexicalOrder(int n)
        {
            IList<int> ret = new List<int>();
            int number = 1;
            for (int i = 0; i < n; i++)
            {
                ret.Add(number);
                if (number * 10 <= n)
                {
                    number *= 10;
                }
                else
                {
                    while (number % 10 == 9 || number + 1 > n)
                    {
                        number /= 10;
                    }
                    number++;
                }
            }
            return ret;
        }
    }
}
