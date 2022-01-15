using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1716
{
    /// <summary>
    /// 1716. 计算力扣银行的钱
    /// </summary>
    public class Class1716
    {
        public int TotalMoney(int n)
        {
            int res = 0;
            if (n <= 7)
            {
                return n * (n + 1) / 2;
            }
            int firstSeven = 28;
            res = firstSeven;
            int countSeven = n / 7;
            //余数
            int remainder = n % 7;
            for (int i = 0; i < countSeven - 1; i++)
            {
                firstSeven += 7;
                res += firstSeven;
            }
            for (int i = 0; i < remainder; i++)
            {
                res += countSeven + 1 + i;
            }

            return res;
        }
    }
}
