using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 根据已知随机数生成函数计算新的随机数
    /// </summary>
    public class TestRand
    {
        //产生的随机数是整数1-7的均匀分布
        private static int Rand7()
        {
            Random random = new Random();
            return random.Next(7) + 1;
        }


        //产生的随机数是整数1-10的均匀分布
        public static int Rand10()
        {
            int x = 0;
            do
            {
                x = (Rand7() - 1) * 7 + Rand7();
            } while (x > 40);
            return x % 10 + 1;
        }

    }

}
