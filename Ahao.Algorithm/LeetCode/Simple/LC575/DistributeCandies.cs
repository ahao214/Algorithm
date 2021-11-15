using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 575. 分糖果
    /// </summary>
    public class DistributeCandies
    {
        public int Method(int[] candyType)
        {
            Array.Sort(candyType);
            int count = 1;
            for (int i = 1; i < candyType.Length && count < candyType.Length / 2; i++)
            {
                if (candyType[i] > candyType[i - 1])
                {
                    count++;
                }
            }
            return count;
        }
    }
}
