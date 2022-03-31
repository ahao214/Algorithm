using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo728
{
    public class Class728
    {
        public IList<int> SelfDividingNumbers(int left, int right)
        {
            IList<int> res = new List<int>();
            for (int i = left; i <= right; i++)
            {
                if (IsDiv(i))
                    res.Add(i);
            }
            return res;
        }


        public bool IsDiv(int num)
        {
            int tmp = num;
            while (tmp > 0)
            {
                int dig = tmp % 10;
                if (dig == 0 || num % dig != 0)
                {
                    return false;
                }
                tmp /= 10;
            }
            return true;
        }

    }
}
