using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 58. 最后一个单词的长度
    /// </summary>
    public class LengthOfLastWord
    {
        public int Method(string s)
        {
            string[] array = s.Split(' ');
            for (var i = array.Length - 1; i >= 0; i--)
            {
                if (!string.IsNullOrEmpty(array[i]))
                {
                    return array[i].Length;
                }
            }
            return 0;
        }
    }
}
