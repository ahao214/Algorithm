using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo8
{
    public class Class8
    {
        public int MyAtoi(string s)
        {
            s = s.Trim();
            if (string.IsNullOrEmpty(s))
                return 0;
            var i = 0;
            while (i < s.Length && s[i] == ' ')
                i++;
            var negatire = false;
            if (i < s.Length && s[i] == '-')
            {
                negatire = true;
                i++;
            }
            else if (i < s.Length && s[i] == '+')
            {
                i++;
            }

            var n = 0;

            while (i < s.Length && char.IsDigit(s[i]))
            {
                var d = s[i] - '0';
                if (n < int.MinValue / 10)
                {
                    return negatire ? int.MinValue : int.MaxValue;
                }
                if (n == int.MinValue / 10 && d > 8)
                {
                    return negatire ? int.MinValue : int.MaxValue;
                }
                n = n * 10 - d;
                i++;
            }
            if (negatire)
            {
                return n;
            }
            if (n == int.MinValue)
                return int.MaxValue;
            else
                return -n;
        }

        public int MyAtoi1(string s)
        {
            s = s.Trim();
            if (string.IsNullOrEmpty(s))
                return 0;
            char[] str = s.ToCharArray();
            var i = 0;
            while (str[i] == ' ' && i < s.Length)
                i++;
            var negatire = false;
            if (i < s.Length && str[i] == '-')
            {
                negatire = true;
                i++;
            }
            else if (i < s.Length && str[i] == '+')
            {
                i++;
            }
            var n = 0;
            try
            {
                while (i < str.Length && char.IsDigit(str[i]))
                {
                    var d = str[i] - '0';
                    checked
                    {
                        n = n * 10 - d;
                    }
                    i++;
                }
                checked
                {
                    return negatire ? n : -n;
                }
            }
            catch (OverflowException)
            {
                return negatire ? int.MinValue : int.MaxValue;
            }
        }
    }
}
