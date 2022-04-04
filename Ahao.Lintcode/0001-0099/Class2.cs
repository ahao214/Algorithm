using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._0001_0099
{

    #region 2 · 尾部的零

    /*
     给定一个整数 n，计算出n!中尾部零的个数。
     */

    #endregion
    
    public class Class2
    {
        public long trailingZeros(long n)
        {
            long res = 0;
            long x = n;
            while (x > 0)
            {
                x /= 5;
                res += x; ;
            }
            return res;
        }
    }
}


