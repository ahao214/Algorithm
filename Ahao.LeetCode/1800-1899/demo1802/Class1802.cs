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


        /// <summary>
        /// 数学推导
        /// </summary>
        /// <param name="n"></param>
        /// <param name="index"></param>
        /// <param name="maxSum"></param>
        /// <returns></returns>
        public int MaxValue2(int n, int index, int maxSum)
        {
            double left = index;
            double right = n - index - 1;
            if (left > right)
            {
                double temp = left;
                left = right;
                right = temp;
            }

            double upper = ((double)(left + 1) * (left + 1) - 3 * (left + 1)) / 2 + left + 1 + (left + 1) + ((left + 1) * (left + 1) - 3 * (left + 1)) / 2 + right + 1;
            if (upper >= maxSum)
            {
                double a = 1;
                double b = -2;
                double c = left + right + 2 - maxSum;
                return (int)Math.Floor((-b + Math.Sqrt(b * b - 4 * a * c)) / (2 * a));
            }

            upper = ((double)2 * (right + 1) - left - 1) * left / 2 + (right + 1) + ((right + 1) * (right + 1) - 3 * (right + 1)) / 2 + right + 1;
            if (upper >= maxSum)
            {
                double a = 1.0 / 2;
                double b = left + 1 - 3.0 / 2;
                double c = right + 1 + (-left - 1) * left / 2 - maxSum;
                return (int)Math.Floor((-b + Math.Sqrt(b * b - 4 * a * c)) / (2 * a));
            }
            else
            {
                double a = left + right + 1; ;
                double b = (-left * left - left - right * right - right) / 2 - maxSum;
                return (int)Math.Floor(-b / a);
            }
        }

    }
}
