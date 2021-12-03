using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo3
{
    /// <summary>
    /// 3. 无重复字符的最长子串
    /// </summary>
    public class Class3
    {
        public int LengthOfLongestSubstring1(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return 0;
            }
            var i = 0;
            var j = 1;
            var len = 1;
            while (i + len <= s.Length && j < s.Length)
            {
                var m = s.IndexOf(s[j], i, j - i);
                if (m >= 0)
                {
                    if (j - i > len)
                    {
                        len = j - i;
                    }
                    i = m + 1;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            if (j - i > len)
            {
                len = j - i;
            }
            return len;
        }
    }
}
