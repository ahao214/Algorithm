using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo219
{
    /*
    219. 存在重复元素 II
    给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
    满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
    */
    public class Class219
    {
        //哈希表
        public bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            Dictionary<int, int> dictionary = new Dictionary<int, int>();
            int length = nums.Length;
            for (int i = 0; i < length; i++)
            {
                int num = nums[i];
                if (dictionary.ContainsKey(num) && i - dictionary[num] <= k)
                {
                    return true;
                }
                if (dictionary.ContainsKey(num))
                {
                    dictionary[num] = i;
                }
                else
                {
                    dictionary.Add(num, i);
                }
            }
            return false;
        }

        //滑动窗口
        public bool ContainsNearbyDuplicate1(int[] nums, int k)
        {
            ISet<int> set = new HashSet<int>();
            int length = nums.Length;
            for (int i = 0; i < length; i++)
            {
                if (i > k)
                {
                    set.Remove(nums[i - k - 1]);
                }
                if (!set.Add(nums[i]))
                {
                    return true;
                }
            }
            return false;
        }

    }
}
