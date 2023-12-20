using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2828
{
    public class Class2828
    {
        public bool IsAcronym(IList<string> words, string s)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < words.Count; i++)
            {
                sb.Append(words[i].Substring(0, 1));
            }
            return sb.ToString() == s;
        }


        public bool IsAcronym2(IList<string> words, string s)
        {
            if (words.Count != s.Length)
            {
                return false;
            }
            for (int i = 0; i < s.Length; i++)
            {
                if (words[i][0] != s[i])
                {
                    return false;
                }
            }
            return true;
        }


    }
}
