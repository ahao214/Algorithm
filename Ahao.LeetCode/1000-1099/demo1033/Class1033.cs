using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1033
{
    public class Class1033
    {
        public int[] NumMovesStones(int a, int b, int c)
        {
            int x = Math.Min(Math.Min(a, b), c);
            int z = Math.Max(Math.Max(a, b), c);
            int y = a + b + c - x - z;

            int[] res = new int[2];
            res[0] = 2;
            if (z - y == 1 && y - x == 1)
            {
                res[0] = 0;
            }
            else if (z - y <= 2 || y - x <= 2)
            {
                res[0] = 1;
            }
            res[1] = z - x - 2;
            return res;
        }
    }
}
