using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo717
{
    public class Class717
    {
        public bool IsOneBitCharacter(int[] bits)
        {
            int i = 0;
            while (i < bits.Length - 1)
            {
                i = bits[i] == 1 ? i + 2 : i + 1;
            }
            if (i == bits.Length - 1)
                return true;
            else
                return false;
        }
    }
}
