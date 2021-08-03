using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 581. 最短无序连续子数组
    /// </summary>
    public class FindUnsortedSubarray
    {
        public int Method(int[] nums)
        {
            int result = 0;
            int len = nums.Length;
            if (IsSorted(nums))
            {
                return result;
            }

            int[] sortedNums = new int[len];
            Array.Copy(nums, sortedNums, len);
            Array.Sort(sortedNums);
            int left = 0;
            int right = len - 1;
            while (nums[left] == sortedNums[left] )
            {
                left++;                
            }
            while (nums[right] == sortedNums[right])
            {
                right--;
            }
            result = right - left + 1;
            return result;
        }

        public bool IsSorted(int[] nums)
        {
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
