using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.BigData
{
    /// <summary>
    /// 用一个随机函数得到另一个随机函数
    /// </summary>
    public class TestFun
    {
        //返回0和1的概率都是50%
        private static int Fun1()
        {
            Random random = new Random();
            return random.Next(2);
        }

        //返回0的概率为25%，返回1的概率为75%
        public static int Fun2()
        {
            int one = Fun1();
            int two = Fun1();
            int tmp = one;
            tmp |= (two << one);
            if (tmp == 0)
                return 0;
            else
                return 1;
        }
    }
}
