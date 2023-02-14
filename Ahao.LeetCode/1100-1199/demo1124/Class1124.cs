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

        /// <summary>
        /// 哈希表
        /// </summary>
        /// <param name="hours"></param>
        /// <returns></returns>
        public int LongestWPI2(int[] hours)
        {
            int n = hours.Length;
            IDictionary<int, int> dictionary = new Dictionary<int, int>();
            int s = 0, res = 0;
            for (int i = 0; i < n; i++)
            {
                s += hours[i] > 8 ? 1 : -1;
                if (s > 0)
                {
                    res = Math.Max(res, i + 1);
                }
                else
                {
                    if (dictionary.ContainsKey(s - 1))
                    {
                        res = Math.Max(res, i - dictionary[s - 1]);
                    }
                }
                if (!dictionary.ContainsKey(s))
                {
                    dictionary.Add(s, i);
                }
            }
            return res;
        }


        public int LongestWPI3(int[] hours)
        {
            int n = hours.Length;
            for (int i = 0; i < n; i++)
            {
                hours[i] = hours[i] > 8 ? 1 : -1;
            }

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = i; j < n; j++)
                {
                    count += hours[j];
                    if (count > 0)
                        res = Math.Max(res, j - i + 1);
                }
                if (n - i <= res)
                    return res;
            }
            return res;

        }


        public int LongestWPI4(int[] hours)
        {
            int sum = 0;
            int res = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < hours.Length; i++)
            {
                int tmp = hours[i] > 8 ? 1 : -1;
                sum += tmp;
                if (sum > 0)
                    res = i + 1;
                else
                {
                    if (!dic.ContainsKey(sum))
                        dic.Add(sum, i);
                    if (dic.ContainsKey(sum - 1))
                        res = Math.Max(res, i - dic.GetValueOrDefault(sum - 1));
                }
            }
            return res;
        }
    }
}
