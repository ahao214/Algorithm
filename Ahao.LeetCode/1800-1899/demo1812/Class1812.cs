using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1812
{
    public class Class1812
    {
        public bool SquareIsWhite(string coordinates)
        {
            return ((coordinates[0] - 'a' + 1) + (coordinates[1] - '0')) % 2 == 1;
        }
    }
}
