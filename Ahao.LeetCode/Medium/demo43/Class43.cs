using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo43
{
    /*
     43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
     */
    public class Class43
    {
        public string Multiply(string num1, string num2)
        {
            if (string.IsNullOrEmpty(num1) || string.IsNullOrEmpty(num2))
            {
                throw new ArgumentException();
            }

            if (num1 == "0" || num2 == "0")
                return "0";

            var n1 = ToIntArray(num1);
            var n2 = ToIntArray(num2);
            var ret = new int[n1.Length + n2.Length];
            for (int i = 0; i < n1.Length; i++)
            {
                for (int j = 0; j < n2.Length; j++)
                {
                    var n = ret[i + j] + n1[i] * n2[j];
                    ret[i + j] = n % 10;
                    ret[i + j + 1] += n / 10;
                }
            }
            var sb = new StringBuilder(ret.Length);
            for (int i = ret.Length - 1; i >= 0; i--)
            {
                if (sb.Length == 0 && ret[i] == 0)
                    continue;
                sb.Append((char)('0' + ret[i]));
            }
            return sb.ToString();
        }

        private int[] ToIntArray(string s)
        {
            var nums = new int[s.Length];
            for (int i = 0, j = s.Length - 1; i < s.Length; i++, j--)
            {
                nums[j] = s[i] - '0';
            }
            return nums;
        }

    }
}
