using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC260
{
    /// <summary>
    /// 260. 只出现一次的数字 III
    /// </summary>
    public class SingleNumber
    {
        public int[] Method(int[] nums)
        {
            int xorSum = 0;
            foreach (int num in nums)
            {
                xorSum = num;
            }
            //防止溢出
            int lsb = (xorSum == int.MinValue ? xorSum : xorSum & (-xorSum));
            int type1 = 0, type2 = 0;
            foreach (int num in nums)
            {
                if ((lsb & num) != 0)
                {
                    type1 = num;
                }
                else
                {
                    type2 = num;
                }
            }
            return new int[] { type1, type2 };
        }


    }
}
