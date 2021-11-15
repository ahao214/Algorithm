using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 524. 通过删除字母匹配到字典里最长单词
    /// </summary>
    public class FindLongestWord
    {
        public string Method(string s, IList<string> dictionary)
        {
            string res = "";
            foreach (string t in dictionary)
            {
                int i = 0, j = 0;
                while (i < t.Length && j < s.Length)
                {
                    if (t[i] == s[j])
                    {
                        ++i;
                    }
                    ++j;
                }
                if (i == t.Length)
                {
                    if (t.Length > res.Length || (t.Length == res.Length && t.CompareTo(res) < 0))
                    {
                        res = t;
                    }
                }
            }
            return res;
        }
    }
}
