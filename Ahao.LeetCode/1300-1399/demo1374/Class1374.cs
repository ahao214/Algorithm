using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1374
{
    public class Class1374
    {
        public string GenerateTheString(int n)
        {
            StringBuilder sb = new StringBuilder();
            if (n % 2 == 1)
            {
                return new string('a', n);
            }
            return new string('a', n - 1) + "b";
        }
    }
}
