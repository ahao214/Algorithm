using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 求有序数列的第1500个数值
    /// </summary>
    public class TestSearch
    {
        /// <summary>
        /// 蛮力方法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int Search(int n)
        {
            int i, count = 0;
            for (i = 1; ; i++)
            {
                if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
                {
                    count++;
                }
                if (count == n)
                    break;
            }
            return i;
        }

        /// <summary>
        /// 数字规律法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int SearchT(int n)
        {
            int[] a = { 0, 2, 3, 4, 5, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30 };
            int res = (n / 22) * 30 + a[n % 22];
            return res;
        }
    }
}
