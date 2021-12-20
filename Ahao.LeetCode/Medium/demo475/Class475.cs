using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo475
{
    /// <summary>
    /// 475. 供暖器
    /// </summary>
    public class Class475
    {
        public int FindRadius(int[] houses, int[] heaters)
        {
            int result = 0;
            Array.Sort(heaters);
            for (int i = 0; i < houses.Length; i++)
            {
                int ans = int.MaxValue;
                for (int j = 0; j < heaters.Length; j++)
                {
                    int curDis = Math.Abs(houses[i] - heaters[j]);
                    ans = Math.Min(curDis, ans);
                }
                result = Math.Max(result, ans);
            }
            return result;
        }


        //排序+二分
        public int FindRadius2(int[] houses, int[] heaters)
        {
            int ans = 0;
            Array.Sort(heaters);
            foreach (int house in houses)
            {
                int i = BinarySearch(heaters, house);
                int j = i + 1;
                int leftDistance = i < 0 ? int.MaxValue : house - heaters[i];
                int rightDistance = j >= heaters.Length ? int.MaxValue : heaters[j] - house;
                int curDistance = Math.Min(leftDistance, rightDistance);
                ans = Math.Max(ans, curDistance);
            }
            return ans;
        }

        public int BinarySearch(int[] nums, int target)
        {
            int left = 0, right = nums.Length - 1;
            if (nums[left] > target)
            {
                return -1;
            }
            while (left < right)
            {
                int mid = (right - left + 1) / 2 + left;
                if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid;
                }
            }
            return left;
        }

    }
}
