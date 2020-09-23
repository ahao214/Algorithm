using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 12.整数转罗马数字
    /// </summary>
    public class IntToRoman
    {
        public string Method(int num)
        {
            int[] nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
            string[] roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < nums.Length; i++)
            {
                while (nums[i] <= num)
                {
                    num -= nums[i];
                    sb.Append(roman[i]);
                }
                if(num ==0)
                {
                    break;
                }
            }
            return sb.ToString();
        }
    }
}
