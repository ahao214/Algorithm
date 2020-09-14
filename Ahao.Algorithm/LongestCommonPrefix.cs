using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 14. 最长公共前缀
    /// </summary>
    public class LongestCommonPrefix
    {
        public string Method(string[] strs)
        {
            string result = string.Empty;
            if (strs.Length == 0)
            {
                return result;
            }

            for (int i = 0; i < strs[0].Length; i++)
            {
                for (int j = 1; j < strs.Length; j++)
                {
                    if (i >= strs[j].Length || !strs[0][i].Equals(strs[j][i]))
                    {
                        return result;
                    }
                }                
                result = strs[0].Substring(0, i + 1);
            }

            return result;
        }

    }
}
