using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    public class HammingDistance
    {
        /// <summary>
        /// 461.汉明距离
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public int Method(int x, int y)
        {
            int xor = x ^ y; //异或，不同为1，相同为0
            int distance = 0;
            while (xor != 0)
            {
                distance += 1;
                xor = xor & (xor - 1);
            }
            return distance;
        }

    }
}
