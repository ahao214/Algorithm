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

    }
}
