using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo719
{
    public class Class719
    {

        //方法一：排序 + 二分查找
        public int SmallestDistancePair(int[] nums, int k)
        {
            Array.Sort(nums);
            int n = nums.Length, left = 0, right = nums[n - 1] - nums[0];
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    int i = BinarySearch(nums, j, nums[j] - mid);
                    cnt += j - i;
                }
                if (cnt >= k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return left;
        }

        public int BinarySearch(int[] nums, int end, int target)
        {
            int left = 0, right = end;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            return left;
        }


        //方法二：排序 + 二分查找 + 双指针
        public int SmallestDistancePair2(int[] nums, int k)
        {
            Array.Sort(nums);
            int n = nums.Length, left = 0, right = nums[n - 1] - nums[0];
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int cnt = 0;
                for (int i = 0, j = 0; j < n; j++)
                {
                    while (nums[j] - nums[i] > mid)
                    {
                        i++;
                    }
                    cnt += j - i;
                }
                if (cnt >= k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return left;
        }

    }
}
