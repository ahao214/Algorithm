using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo32
{
    /*
     32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
     */
    public class Class32
    {
        public int LongestValidParentheses(string s)
        {
            int left = 0, right = 0, ans = 0;
            int n = s.Length;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    left++;
                else
                    right++;
                if (left == right)
                    ans = Math.Max(ans, right);
                else if (right > left)
                    left = right = 0;
            }
            left = right = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '(')
                    left++;
                else
                    right++;
                if (left == right)
                    ans = Math.Max(ans, left);
                else if (left > right)
                    left = right = 0;
            }
            return ans * 2;
        }
    }

}
