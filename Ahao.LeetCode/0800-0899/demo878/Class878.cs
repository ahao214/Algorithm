using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo878
{
    public class Class878
    {
        const int MOD = 1000000007;
        /// <summary>
        /// 方法一：容斥原理 + 二分查找
        /// </summary>
        /// <param name="n"></param>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int NthMagicalNumber(int n, int a, int b)
        {
            long l = Math.Min(a, b);
            long r = (long)n * Math.Min(a, b);
            int c = LCM(a, b);
            while (l <= r)
            {
                long mid = (l + r) / 2;
                long cnt = mid / a + mid / b - mid / c;
                if (cnt >= n)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return (int)((r + 1) % MOD);
        }
     
        /// <summary>
        /// 方法二：找规律
        /// </summary>
        /// <param name="n"></param>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int NthMagicalNumber2(int n, int a, int b)
        {
            int c = LCM(a, b);
            int m = c / a + c / b - 1;
            int r = n % m;
            int res = (int)((long)c * (n / m) % MOD);
            if (r == 0)
            {
                return res;
            }
            int addA = a, addB = b;
            for (int i = 0; i < r - 1; ++i)
            {
                if (addA < addB)
                {
                    addA += a;
                }
                else
                {
                    addB += b;
                }
            }
            return (res + Math.Min(addA, addB) % MOD) % MOD;
        }

        public int LCM(int a, int b)
        {
            return a * b / GCD(a, b);
        }

        public int GCD(int a, int b)
        {
            return b != 0 ? GCD(b, a % b) : a;
        }

    }
}
