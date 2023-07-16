using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo415
{
    internal class Class415
    {
        public string AddStrings(string num1, string num2)
        {
            StringBuilder sb = new StringBuilder();
            int index1 = num1.Length - 1, index2 = num2.Length - 1;
            int carry = 0;
            while (index1 >= 0 || index2 >= 0 || carry != 0)
            {
                int digit1 = index1 >= 0 ? num1[index1] - '0' : 0;
                int digit2 = index2 >= 0 ? num2[index2] - '0' : 0;
                int sum = digit1 + digit2 + carry;
                sb.Append(sum % 10);
                carry = sum / 10;
                index1--;
                index2--;
            }
            StringBuilder sb2 = new StringBuilder();
            for (int i = sb.Length - 1; i >= 0; i--)
            {
                sb2.Append(sb[i]);
            }
            return sb2.ToString();
        }

    }
}
