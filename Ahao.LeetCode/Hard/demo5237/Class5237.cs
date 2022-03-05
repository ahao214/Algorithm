using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo5237
{
    /*
     5237. 得到回文串的最少操作次数
给你一个只包含小写英文字母的字符串 s 。

每一次 操作 ，你可以选择 s 中两个 相邻 的字符，并将它们交换。

请你返回将 s 变成回文串的 最少操作次数 。

注意 ，输入数据会确保 s 一定能变成一个回文串。
     */
    public class Class5237
    {
        public int minMovesToMakePalindrome(string s)
        {
            int ans = 0;
            while (s.Length > 1)
            {
                int r = s.Length - 1;
                while (r > 0 && s[r] != s[0]) r -= 1;
                if (r == 0)
                {
                    ans += s.Length / 2;
                    s = s.Substring(1);
                }
                else
                {
                    ans += s.Length - r - 1;
                    s = s.Substring(1, r - 1) + s.Substring(r + 1);
                }
            }
            return ans;
        }
    }
}
