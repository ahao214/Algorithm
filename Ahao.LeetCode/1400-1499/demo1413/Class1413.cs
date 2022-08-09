using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1413
{
    public class Class1413
    {
        /// <summary>
        /// 方法一：贪心
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinStartValue(int[] nums)
        {
            int accSum = 0, accSumMin = 0;
            foreach (int num in nums)
            {
                accSum += num;
                accSumMin = Math.Min(accSumMin, accSum);
            }
            return -accSumMin + 1;
        }



        /// <summary>
        /// 方法二：二分查找
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinStartValue2(int[] nums)
        {
            int m = nums.Min();
            if (m >= 0)
            {
                return 1;
            }
            int left = 1, right = -m * nums.Length + 1;
            while (left < right)
            {
                int medium = (left + right) / 2;
                if (Valid(medium, nums))
                {
                    right = medium;
                }
                else
                {
                    left = medium + 1;
                }
            }
            return left;
        }

        public bool Valid(int startValue, int[] nums)
        {
            foreach (int num in nums)
            {
                startValue += num;
                if (startValue <= 0)
                {
                    return false;
                }
            }
            return true;
        }

    }
}
