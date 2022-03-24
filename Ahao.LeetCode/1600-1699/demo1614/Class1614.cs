using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1614
{
    public class Class1614
    {
        public int MaxDepth(string s)
        {
            int res = 0;
            int count = 0;
            if (string.IsNullOrEmpty(s))
            {
                return res;
            }
            foreach (var c in s)
            {
                if (c == '(')
                {
                    count++;
                    res = Math.Max(res, count);
                }
                if (c == ')')
                {
                    count--;
                }
            }
            return res;
        }

        public int MaxDepth1(string s)
        {
            int ans = 0, size = 0;
            foreach (char ch in s)
            {
                if (ch == '(')
                {
                    ++size;
                    ans = Math.Max(ans, size);
                }
                else if (ch == ')')
                {
                    --size;
                }
            }
            return ans;
        }
    }
}
