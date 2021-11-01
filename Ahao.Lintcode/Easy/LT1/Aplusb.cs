using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode.Easy
{
    public class Aplusb
    {
        /// <summary>
        /// 1 · A + B 问题
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int Method(int a, int b)
        {
            if (a == b)
            {
                return a * 2;
            }
            return (a * a - b * b) / (a - b);
        }
    }
}
