using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC160
{
    /// <summary>
    /// NC160 二分查找
    /// </summary>
    public class Class160
    {
        public int search(List<int> nums, int target)
        {
            if (nums == null || nums.Count == 0)
            {
                return -1;
            }
            int res = -1;
            int left = 0;
            int right = nums.Count - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                {
                    res = mid;
                    break;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return res;
        }
    }
}
