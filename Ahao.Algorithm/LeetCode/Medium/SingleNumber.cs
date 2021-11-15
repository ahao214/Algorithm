using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 137.只出现一次的数字(2)
    /// </summary>
    public class SingleNumber
    {
        public int Method(int[] nums)
        {
            long sumNums = 0;
            long sumHS = 0;
            HashSet<int> hs = new HashSet<int>();
            foreach (int i in nums)
            {
                sumNums += i;
                hs.Add(i);
            }
            foreach (int item in hs)
            {
                sumHS += item;
            }
            long result = (sumHS * 3 - sumNums) / 2;
            return (int)result;
        }
    }
}
