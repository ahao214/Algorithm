using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1250
{
    public class Class1250
    {
        public bool IsGoodArray(int[] nums)
        {
            int divisor = nums[0];
            foreach (int num in nums)
            {
                divisor = GCD(divisor, num);
                if (divisor == 1)
                {
                    break;
                }
            }
            return divisor == 1;
        }

        public int GCD(int num1, int num2)
        {
            while (num2 != 0)
            {
                int temp = num1;
                num1 = num2;
                num2 = temp % num2;
            }
            return num1;
        }
    }
}
