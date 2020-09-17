using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 387.字符串中的第一个唯一字符
    /// </summary>
    public class FirstUniqChar
    {
        public int Method(string s)
        {
            int result = -1;
            Dictionary<char, int> strDic = new Dictionary<char, int>();
            for (int i = 0; i < s.Length; i++)
            {
                if (strDic.ContainsKey(s[i]))
                {
                    strDic[s[i]] += 1;
                }
                else
                {
                    strDic.Add(s[i], 1);
                }
            }

            for (int i = 0; i < s.Length; i++)
            {
                if (strDic[s[i]] == 1)
                {
                    result = i;
                    break;
                }
            }

            return result;
        }

    }
}
