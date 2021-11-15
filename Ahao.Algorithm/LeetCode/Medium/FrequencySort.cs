using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 451. 根据字符出现频率排序
    /// </summary>
    public class FrequencySort
    {
        public string Method(string s)
        {
            Dictionary<char, int> dictionary = new Dictionary<char, int>();
            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (dictionary.ContainsKey(c))
                {
                    dictionary[c]++;
                }
                else
                {
                    dictionary.Add(c, 1);
                }
            }

            List<char> lst = new List<char>(dictionary.Keys);
            lst.Sort((a, b) => dictionary[b] - dictionary[a]);
            StringBuilder stringBuilder = new StringBuilder();
            
            for(int i=0;i<lst.Count;i++)
            {
                char c = lst[i];
                int fre = dictionary[c];
                for(int j=0;j<fre;j++)
                {
                    stringBuilder.Append(c);
                }
            }
            return stringBuilder.ToString();
        }

    }
}
