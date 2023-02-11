using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2335
{
    public class Class2335
    {
        public int FillCups(int[] amount)
        {
            Array.Sort(amount);
            if (amount[2] > amount[1] + amount[0])
            {
                return amount[2];
            }
            return (amount[0] + amount[1] + amount[2] + 1) / 2;
        }

    }
}
