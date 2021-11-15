using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1227. 飞机座位分配概率
    /// </summary>
    public class NthPersonGetsNthSeat
    {
        public double Method(int n)
        {
            if (n == 1)
            {
                return 1.0;
            }
            return 0.5;
        }
    }
}
