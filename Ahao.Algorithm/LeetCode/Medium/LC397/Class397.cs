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

        /// <summary>
        /// 记忆化搜索
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        Dictionary<int, int> dic = new Dictionary<int, int>();
        public int IntegerReplacement2(int n)
        {
            if (n == 1)
            {
                return 0;
            }

            if (!dic.ContainsKey(n))
            {
                if (n % 2 == 0)
                {
                    dic.Add(n, 1 + IntegerReplacement2(n / 2));
                }
                else
                {
                    dic.Add(n, 2 + Math.Min(IntegerReplacement2(n / 2), IntegerReplacement2(n / 2 + 1)));
                }
            }
            return dic[n];
        }

        /// <summary>
        /// 贪心
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int IntegerReplacement3(int n)
        {
            int ans = 0;
            while (n != 1)
            {
                if (n % 2 == 0)
                {
                    ++ans;
                    n /= 2;
                }
                else if (n % 4 == 1)
                {
                    ans += 2;
                    n / = 2;
                }
                else
                {
                    if (n == 3)
                    {
                        ans += 2;
                        n = 1;
                    }
                    else
                    {
                        ans += 2;
                        n = n / 2 + 1;
                    }
                }
            }
            return ans;
        }
    }
}
