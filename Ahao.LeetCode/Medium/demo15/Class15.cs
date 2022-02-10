using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo15
{
    /*
    15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
     */
    public class Class15
    {
        public IList<IList<int>> ThreeSum(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return new List<IList<int>>(0);

            Array.Sort(nums);
            var map = new Dictionary<int, int>(nums.Length);
            foreach (var num in nums)
            {
                if (map.TryGetValue(num, out var count))
                {
                    map[num] = count + 1;
                }
                else
                {
                    map[num] = 1;
                }
            }
            var results = new List<IList<int>>();
            for (int i = 0; i < nums.Length; i++)
            {
                var n1 = nums[i];
                map[n1]--;
                TwoSum(nums, i, -n1, map, results);
                map[n1]++;
                while (i + 1 < nums.Length && nums[i + 1] == n1)
                    i++;
            }
            return results;
        }

        private void TwoSum(int[] nums, int i, int target, Dictionary<int, int> map, List<IList<int>> results)
        {
            var n1 = -target;
            for (int j = i + 1; j < nums.Length; j++)
            {
                var n2 = nums[j];
                var n3 = target - n2;
                if (n3 < n2)
                    break;
                if (map.TryGetValue(n3, out var count))
                {
                    if (n2 == n3)
                    {
                        if (count > 1)
                            results.Add(new[] { n1, n2, n3 });
                    }
                    else
                    {
                        if (count > 0)
                            results.Add(new[] { n1, n2, n3 });
                    }
                }
                while (j + 1 < nums.Length && nums[j + 1] == n2)
                    j++;
            }
        }

    }
}
