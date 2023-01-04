using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1802
{
    public class Class1802
    {
        /// <summary>
        /// 贪心+二分查找
        /// </summary>
        /// <param name="n"></param>
        /// <param name="index"></param>
        /// <param name="maxSum"></param>
        /// <returns></returns>
        public int MaxValue(int n, int index, int maxSum)
        {
            int left = 1, right = maxSum;
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (Valid(mid, n, index, maxSum))
                {
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return left;
        }

        public bool Valid(int mid, int n, int index, int maxSum)
        {
            int left = index;
            int right = n - index - 1;
            return mid + Cal(mid, left) + Cal(mid, right) <= maxSum;
        }

        public long Cal(int big, int length)
        {
            if (length + 1 < big)
            {
                int small = big - length;
                return (long)(big - 1 + small) * length / 2;
            }
            else
            {
                int ones = length - (big - 1);
                return (long)big * (big - 1) / 2 + ones;
            }
        }



    }
}
