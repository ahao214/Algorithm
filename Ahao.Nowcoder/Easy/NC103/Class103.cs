using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC103
{
    /// <summary>
    /// NC103 反转字符串
    /// </summary>
    public class Class103
    {
        public string solve(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return "";
            }
            char[] c = str.ToCharArray();
            int n = c.Length;
            for (int left = 0, right = n - 1; left < right; ++left, --right)
            {
                char tmp = c[left];
                c[left] = c[right];
                c[right] = tmp;
            }
            return new string(c);
        }
    }
}
