using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 在一个字符串中找到第一个只出现一次的字符
    /// </summary>
    public class TestFindFirstWord
    {
        public static char FindFirstWord(Char[] array)
        {
            int[] hash = new int[256];
            for (int i = 0; i < array.Length; i++)
            {
                hash[Convert.ToInt32(array[i])]++;
            }
            for (int i = 0; i < array.Length; i++)
            {
                if (hash[Convert.ToInt32(array[i])] == 1)
                    return array[i];
            }
            return ' ';
        }
    }
}
