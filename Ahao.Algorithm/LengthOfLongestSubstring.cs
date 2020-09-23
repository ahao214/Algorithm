using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 3.无重复字符的最长子串
    /// </summary>
    public class LengthOfLongestSubstring
    {
        public int Method(string s)
        {
            List<char> lst = new List<char>();
            int maxLength = 0;
            for (int i = 0; i < s.Length; i++)
            {                            
                if (lst.Contains(s[i]))
                {
                    //移除0到重复字符
                    lst.RemoveRange(0, lst.IndexOf(s[i]) + 1);
                }
                lst.Add(s[i]);
                maxLength = lst.Count > maxLength ? lst.Count : maxLength;
            }
            return maxLength;
        }
    }
}
