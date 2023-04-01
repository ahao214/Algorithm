using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo831
{
    public class Class831
    {

        string[] country = { "", "+*-", "+**-", "+***-" };

        public string MaskPII(string s)
        {
            int at = s.IndexOf("@");
            if (at > 0)
            {
                s = s.ToLower();
                return (s[0] + "*****" + s.Substring(at - 1)).ToLower();
            }
            StringBuilder sb = new StringBuilder();
            foreach (char c in s)
            {
                if (char.IsDigit(c))
                {
                    sb.Append(c);
                }
            }
            s = sb.ToString();
            return country[s.Length - 10] + "***-***-" + s.Substring(s.Length - 4);
        }
    }
}
