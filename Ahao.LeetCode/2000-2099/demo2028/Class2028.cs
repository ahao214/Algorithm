using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2028
{
    public class Class2028
    {
        public int[] MissingRolls(int[] rolls, int mean, int n)
        {
            int sum = rolls.Sum();
            int m = rolls.Length;
            //缺失的数字的总和
            int missSum = (m + n) * mean - sum;
            //缺失的数字的总和必须在n和n*6之间
            if (missSum < n || missSum > n * 6)
                return new int[0];
            int a = missSum / n, b = missSum % n;
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
            {
                if (i < b)
                    res[i] = a + 1;
                else
                    res[i] = a;
            }
            return res;
        }
    }
}
