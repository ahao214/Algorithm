using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo374
{
    public class Class374
    {
        public int GuessNumber(int n)
        {
            int left = 1, right = n;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                //if (guess(mid) <= 0)
                //    right = mid;
                //else
                //    left = mid + 1;
            }
            return left;
        }

        //int guess(int num);
    }
}
