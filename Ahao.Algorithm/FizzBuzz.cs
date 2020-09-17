using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 412.Fizz Buzz
    /// </summary>
    public class FizzBuzz
    {
        public IList<string> Method(int n)
        {
            var lst = new List<string>();

            for (int i = 1; i <= n; i++)
            {
                if (i % 3 == 0 && i % 5 == 0)
                {
                    lst.Add("FizzBuzz");
                }
                else if (i % 3 == 0 && i % 5 != 0)
                {
                    lst.Add("Fizz");
                }
                else if (i % 3 != 0 && i % 5 == 0)
                {
                    lst.Add("Buzz");
                }
                else
                {
                    lst.Add(i.ToString());
                }
            }

            return lst;
        }
    }
}
