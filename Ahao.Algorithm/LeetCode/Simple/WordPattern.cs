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
            if (pattern.Count() != subStrs.Count())
            {
                return false;
            }
            for (int i = 0; i < pattern.Count(); i++)
            {
                //判断字母首次出现位置
                int first = pattern.IndexOf(pattern[i]);
                if (i == first)
                {
                    if (lst.Contains(subStrs[i]))
                    {
                        return false;
                    }
                    lst.Add(subStrs[i]);
                }
                else
                {
                    //判断对应的数据是否相等
                    if (lst[first] != subStrs[i])
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
