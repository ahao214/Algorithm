using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 709. 转换成小写字母
    /// </summary>
    public class ToLowerCase
    {
        public string Method(string str)
        {
            var chars = str.ToCharArray();
            var stringBuilder = new StringBuilder();
            var temp = (char)32;
            for (int i = 0; i < chars.Length; i++)
            {
                if (chars[i] > 64 && chars[i] < 91)
                {
                    chars[i] += temp;
                }
                stringBuilder.Append(chars[i]);
            }
            return stringBuilder.ToString();
        }
    }
}
