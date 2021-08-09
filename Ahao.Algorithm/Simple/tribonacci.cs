using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1137. 第 N 个泰波那契数
    /// </summary>
    public class Tribonacci
    {
        public int Method(int n)
        {
            if (n == 0)
                return 0;
            if (n <= 2)
                return n;

            int[] result = new int[n + 1];
            result[0] = 0;
            result[1] = 1;
            result[2] = 1;
            for (int i = 3; i <= n; i++)
            {
                result[i] = result[i - 3] + result[i - 2] + result[i - 1];
            }
            return result[n];
        }


        /// <summary>
        /// 递归实现
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int FuncOne(int n)
        {
            if (n <= 1)
                return n;
            return FuncOne(n - 1) + FuncOne(n - 2);
        }

        /// <summary>
        /// 循环实现
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int FuncTwo(int n)
        {
            if (n <= 1)
            {
                return n;
            }
            int first = 0;
            int second = 1;
            for (int i = 0; i < n - 1; i++)
            {
                int sum = first + second;
                first = second;
                second = sum;
            }
            return second;

        }
    }
}
