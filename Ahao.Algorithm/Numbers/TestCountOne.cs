using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 求二进制数中1的个数
    /// </summary>
    public class TestCountOne
    {
        //移位法
        public static int CountOne(int n)
        {
            int count = 0;
            while (n>0)
            {
                if ((n & 1) == 1)    //判断最后一位是否为1
                    count++;
                n >>= 1;    //移位丢掉最后一位
            }
            return count;
        }
    }
}
