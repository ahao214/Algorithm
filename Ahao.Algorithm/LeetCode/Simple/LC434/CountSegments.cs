using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 434. 字符串中的单词数
    /// </summary>
    public class CountSegments
    {
        public int Method(string s)
        {
            int res = 0;
            for (int i = 0; i < s.Length;)
            {
                if (s[i] != ' ')
                {
                    while (i < s.Length && s[i] != ' ')
                    {
                        i++;
                    }
                    res++;
                }
                while (i < s.Length && s[i] == ' ')
                {
                    i++;
                }
            }
            return res;

        }
    }
}
