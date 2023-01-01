using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6278
{
    public class Class6278
    {
        public int CountDigits(int num)
        {
            int res = 0;
            int oldNum = num;
            while (num != 0)
            {
                if (oldNum % (num % 10) == 0)
                {
                    res++;
                }
                num /= 10;
            }
            return res;
        }

        public int CountDigits2(int num)
        {
            int[] N = new int[10];
            int sum = 0;
            int tmp = num;
            while (num > 0)
            {
                int a = num % 10;
                N[a]++;
                num /= 10;
            }
            for (int i = 1; i < N.Length; i++)
            {
                if (tmp % i == 0 && N[i] > 0)
                {
                    sum += N[i];
                }
            }
            return sum;
        }
    }
}
