using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1124
{
    public class Class1124
    {
        /// <summary>
        /// 贪心
        /// </summary>
        /// <param name="hours"></param>
        /// <returns></returns>
        public int LongestWPI(int[] hours)
        {
            int n = hours.Length;
            int[] s = new int[n + 1];
            Stack<int> stk = new Stack<int>();
            stk.Push(0);
            for (int i = 1; i <= n; i++)
            {
                s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
                if (s[stk.Peek()] > s[i])
                {
                    stk.Push(i);
                }
            }

            int res = 0;
            for (int r = n; r >= 1; r--)
            {
                while (stk.Count > 0 && s[stk.Peek()] < s[r])
                {
                    res = Math.Max(res, r - stk.Pop());
                }
            }
            return res;
        }


    }
}
