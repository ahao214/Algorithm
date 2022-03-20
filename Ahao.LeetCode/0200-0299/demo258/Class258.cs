using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo258
{
    public class Class258
    {
        public int AddDigits(int num)
        {
            return (num - 1) % 9 + 1;
        }


        public int AddDigits1(int num)
        {
            while (num >= 10)
            {
                int sum = 0;
                while (num > 0)
                {
                    sum += num % 10;
                    num /= 10;
                }
                num = sum;
            }
            return num;
        }
    }
}
