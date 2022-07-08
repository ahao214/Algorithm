using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1217
{
    public class Class1217
    {
        public int MinCostToMoveChips(int[] position)
        {
            int even = 0, odd = 0;
            foreach (int pos in position)
            {
                if ((pos & 1) != 0)
                    odd++;
                else
                    even++;
            }
            return Math.Min(odd, even);
        }
    }
}
