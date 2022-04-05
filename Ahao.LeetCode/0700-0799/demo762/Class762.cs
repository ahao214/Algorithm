using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo762
{
    public class Class762
    {
        public int CountPrimeSetBits(int left, int right)
        {
            int cnt = 0;
            for (int i = left; i <= right; i++)
            {
                if (IsPar(CountOnes(i)))
                    cnt++;
            }
            return cnt;
        }

        //计算数字1的个数
        public int CountOnes(int num)
        {
            int cnt = 0;
            while (num != 0)
            {
                if (num % 2 == 1)
                {
                    cnt++;
                }
                num >>= 1;
            }
            return cnt;
        }

        public bool IsPar(int num)
        {
            if (num < 2)
                return false;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }

    }
}
