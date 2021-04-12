using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 如何查找没有重复字符的最长子串
    /// </summary>
    public class TestLengthOfLongestSubstrin
    {
        public int Method(char[] str)
        {
            int i, j;
            int maxlen = 0; //要初始化，不然产生意外结果
            int n = str.Length;
            int[] arr = new int[255];

            for (i = 0, j = 0; j < n; j++)
            {
                while (arr[str[j]] == 1)
                {
                    arr[str[i]] = 0;
                    ++i;
                }
                arr[str[j]] = 1;
                maxlen = maxlen > (j - i) ? maxlen : j - i + 1;
            }
            return maxlen;
        }
    }
}
