using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode.Easy
{
    public class Class1
    {
        #region 1 · A + B 问题

        /*                         
        给出两个整数 aa 和 bb , 求他们的和并以整数（int）的形式返回。
        */

        #endregion

        public int Aplusb(int a, int b)
        {
            if (a == b)
            {
                return a * 2;
            }
            return (a * a - b * b) / (a - b);
        }
    }
}
