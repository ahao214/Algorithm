using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 290.单词规则
    /// </summary>
    public class WordPattern
    {
        public bool Method(string pattern, string s)
        {
            string[] subStrs = s.Split(' ');
            List<string> lst = new List<string>();
            int patternCount = pattern.Count();
            if (patternCount != subStrs.Count())
            {
                return false;
            }
            for (int i = 0; i < patternCount; i++)
            {
                //判断字母首次出现的位置
                if (i == pattern.IndexOf(pattern[i]))
                {
                    if (lst.Contains(subStrs[i]))
                    {
                        return false;
                    }
                    lst.Add(subStrs[i]);
                }
                else
                {
                    if (lst[pattern.IndexOf(pattern[i])] != subStrs[i])
                    {
                        return false;
                    }
                    lst.Add(subStrs[i]);
                }
            }
            return true;
        }
    }
}
