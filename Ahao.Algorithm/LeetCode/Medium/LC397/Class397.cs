using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Medium
{
    /// <summary>
    /// 397. 整数替换
    /// </summary>
    public class Class397
    {
        /// <summary>
        /// 枚举所有的情况
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int IntegerReplacement(int n)
        {
            if (n == 1)
            {
                return 0;
            }
            if (n % 2 == 0)
            {
                return 1 + IntegerReplacement(n / 2);
            }
            return 2 + Math.Min(IntegerReplacement(n / 2), IntegerReplacement(n / 2 + 1));
        }


    }
}
