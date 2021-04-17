using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 判断一个自然数是否是某个数的二次方
    /// </summary>
    public class TestIsPower
    {
        public static bool IsPower(int n)
        {
            int i;
            int m;
            if (n <= 0)
            {
                Console.WriteLine(n + "不是自然数");
                return false;
            }
            for (i = 1; i < n; i++)
            {
                m = i * i;
                if (m == n)
                {
                    return true;
                }
                else if (m > n)
                {
                    return false;
                }
            }
            return false;
        }

        /// <summary>
        /// 二分查找法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static bool IsPowerT(int n)
        {
            int low = 1;
            int high = n;
            int mid;
            int power;
            while (low < high)
            {
                mid = (low + high) / 2;
                power = mid * mid;
                //接着在1-mid区间内查找
                if (power > n)
                {
                    high = mid - 1;
                }
                //接着在mid+1-n区间内查找
                else if (power < n)
                {
                    low = mid + 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// 减法运算法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static bool IsPowerA(int n)
        {
            int minus = 1;
            while (n > 0)
            {
                n = n - minus;
                //n是某个数的二次方
                if (n == 0)
                    return true;
                //n不是某个数的二次方
                else if (n < 0)
                    return false;
                //每次减数都加2
                else
                    minus += 2;
            }
            return false;
        }


    }
}
