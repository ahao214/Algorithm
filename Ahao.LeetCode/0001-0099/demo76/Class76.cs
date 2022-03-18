using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo76
{
    /*
     76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
     */
    public class Class76
    {
        public string MinWindow(string s, string t)
        {
            Dictionary<char, List<int>> dicT = new Dictionary<char, List<int>>();
            string res = s + "end";

            for (var i = 0; i < t.Length; i++)
            {
                if (!dicT.ContainsKey(t[i]))
                    dicT.Add(t[i], new List<int>() { 1 });
                else
                    dicT[t[i]][0] += 1;
            }

            for (var j = 0; j < s.Length; j++)
            {
                if (dicT.ContainsKey(s[j]))
                {
                    dicT[s[j]].Add(j);

                    var fullhead = j;
                    foreach (var item in dicT)
                    {
                        if (item.Value.Count() <= item.Value[0])
                        {
                            fullhead = -1;
                            break;
                        }
                        else
                            fullhead = Math.Min(item.Value[item.Value.Count() - item.Value[0]], fullhead);
                    }

                    if (fullhead != -1 && res.Length > j - fullhead + 1)
                        res = s.Substring(fullhead, j - fullhead + 1);
                }
            }

            if (res.Length <= s.Length)
                return res;
            else
                return "";
        }

    }
}
