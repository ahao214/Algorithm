using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6291
{
    public class Class6291
    {
        public int DifferenceOfSum(int[] nums)
        {
            int eleSum = 0;
            int bitSum = 0;
            eleSum = nums.Sum();
            for (int i = 0; i < nums.Length; i++)
            {
                bitSum += BitSum(nums[i]);
            }
            return Math.Abs(eleSum - bitSum);
        }

        public int BitSum(int num)
        {
            int bitSum = 0;
            while (num != 0)
            {
                bitSum += num % 10;
                num /= 10;
            }
            return bitSum;
        }
    }
}
