using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo12
{
    public class Class12
    {
        private readonly string[] Romans = new[] { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

        private readonly int[] Values = new[] { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

        public string IntToRoman(int num)
        {
            var res = new StringBuilder();
            var i = Romans.Length - 1;
            while (num > 0)
            {
                if (num >= Values[i])
                {
                    res.Append(Romans[i]);
                    num -= Values[i];
                }
                else
                {
                    i--;
                }
            }
            return res.ToString();
        }
    }
}
