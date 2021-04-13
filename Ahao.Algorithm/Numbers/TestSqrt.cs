using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 不使用库函数求解整数X的平方根
    /// </summary>
    public class TestSqrt
    {
        public static int Sqrt(int x)
        {
            if (x == 0)
                return 0;

            //int的最大值为2的32次方，平方根的最大值为46341
            int left = 1, right = 46341;
            int mid = 0;

            while (left < right)
            {
                //中间值与左右边界的和的一半是相等的，那么现在的中间值就是上一循环中已经使用过的
                //直接退出循环即可
                if (mid == (left + right) / 2)
                {
                    break;
                }
                mid = (left + right) / 2;
                if (mid * mid == x)
                {
                    return mid;
                }
                else if (mid * mid < x)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return mid;
        }
    }
}
