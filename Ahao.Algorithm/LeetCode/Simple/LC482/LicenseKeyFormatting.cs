using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 482. 密钥格式化
    /// </summary>
    public class LicenseKeyFormatting
    {
        public string Method(string s, int k)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = s.Length - 1, cnt = 0; i >= 0; i--)
            {
                if (s[i] == '-') continue;
                if (cnt == k && (cnt = 0) >= 0) sb.Append("-");
                sb.Append(s[i]);
                cnt++;
            }
            char[] cs = sb.ToString().ToCharArray();
            Array.Reverse(cs);
            return new string(cs).ToUpper();
        }
    }
}
