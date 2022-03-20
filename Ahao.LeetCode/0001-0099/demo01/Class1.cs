using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    public class Class1
    {
        public int[] TwoSum(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                var nj = target - nums[i];
                //Array.IndexOf 方法从数组中查找指定对象的下标
                //nj 表示要查找的对象
                //i+1 表示查找的开始位置
                var j = Array.IndexOf(nums, nj, i + 1);
                if (j >= 0)
                {
                    return new[] { i, j };
                }
            }
            return Array.Empty<int>();
        }

        public int[] TwoSum2(int[] nums, int target)
        {
            var map = new Dictionary<int, int>(nums.Length);
            for (int i = 0; i < nums.Length; i++)
            {
                map[nums[i]] = i;
            }
            for (int i = 0; i < nums.Length; i++)
            {
                var nj = target - nums[i];
                if (map.ContainsKey(nj))
                {
                    var j = map[nj];
                    if (j > i)
                    {
                        return new[] { i, j };
                    }
                }
            }
            return Array.Empty<int>();
        }


        #region 两数之和-升序排列的数组
        /// <summary>
        /// 二分方法
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public int[] TwoSum3(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                int low = i, high = nums.Length - 1;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (nums[mid] == target - nums[i])
                    {
                        return new int[] { i, mid };
                    }
                    else if (nums[mid] > target - nums[i])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
            return new int[] { 0 };
        }

        /// <summary>
        /// 双指针
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public int[] TwoSum4(int[] nums, int target)
        {
            int low = 0, high = nums.Length - 1;
            while (low <= high)
            {
                int sum = nums[low] + nums[high];
                if (sum == target)
                {
                    return new int[] { low, high };
                }
                else if (sum < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
            return new int[] { 0 };
        }

        #endregion
    }
}
