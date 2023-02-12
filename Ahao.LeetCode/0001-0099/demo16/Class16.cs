using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo16
{
    public class Class16
    {
        public int ThreeSumClosest(int[] nums, int target)
        {
            Array.Sort(nums);
            int reSum = nums[0] + nums[1] + nums[2];
            for (int i = 0; i < nums.Length - 2; i++)
            {
                int L = i + 1;
                int R = nums.Length - 1;
                while (L < R)
                {
                    int sum = nums[i] + nums[L] + nums[R];
                    if (sum == target) return target;
                    if (Math.Abs(sum - target) < Math.Abs(reSum - target)) reSum = sum;
                    if (sum > target) R--;
                    else L++;
                }
            }
            return reSum;
        }
    }
}
