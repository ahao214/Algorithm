using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 441. 排列硬币
    /// </summary>
    public class ArrangeCoins
    {
        public int Method(int n)
        {
            #region 第一种，超时

            //int k;
            //int sum = 0;
            //if (n == 1)
            //{
            //	return 1;
            //}

            //for (k= 1; k < n; k++)
            //{
            //	sum += k;
            //	if (sum > n)
            //		break;
            //}
            //return k - 1;

            #endregion

            #region

            int i = 1;
            while (n >= i)
            {
                n -= i;
                i++;
            }
            return i - 1;

            #endregion
        }
    }
}
