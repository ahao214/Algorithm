using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo821
{
    public class Class821
    {
        public int[] ShortestToChar(string s, char c)
        {
            int len = s.Length;
            int[] ans = new int[len];
            for (int i = 0, idx = -len; i < len; i++)
            {
                if (s[i] == c)
                {
                    idx = i;
                }
                ans[i] = i - idx;
            }
            for (int i = len - 1, idx = 2 * len; i >= 0; i--)
            {
                if (s[i] == c)
                    idx = i;
                ans[i] = Math.Min(ans[i], idx - i);
            }
            return ans;
        }
    }
}
