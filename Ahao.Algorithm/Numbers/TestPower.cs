using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 计算一个数的n次方
    /// </summary>
    public class TestPower
    {
        #region 蛮力方法

        public static double Power(double d,int n)
        {
            if (n == 0)
                return 1;
            if (n == 1)
                return d;

            double result = 1;
            int i;
            if (n>0)
            {
                for(i=1;i<=n;i++)
                {
                    result *= d;
                }
                return result;
            }
            else
            {
                for(i=1;i<=Math .Abs (n);i++)
                {
                    result = result / d;
                }
            }
            return result;
        }


        #endregion


    }
}
