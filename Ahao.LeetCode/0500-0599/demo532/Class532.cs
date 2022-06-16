using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo532
{
    public class Class532
    {
        /// <summary>
        /// 哈希表
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        public int FindPairs(int[] nums, int k)
        {
            ISet<int> visited = new HashSet<int>();
            ISet<int> res = new HashSet<int>();
            foreach (int num in nums)
            {
                if (visited.Contains(num - k))
                {
                    res.Add(num - k);
                }
                if (visited.Contains(num + k))
                {
                    res.Add(num);
                }
                visited.Add(num);
            }
            return res.Count;
        }



        /// <summary>
        /// 排序 + 双指针
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        public int FindPairs2(int[] nums, int k)
        {
            Array.Sort(nums);
            int n = nums.Length, y = 0, res = 0;
            for (int x = 0; x < n; x++)
            {
                if (x == 0 || nums[x] != nums[x - 1])
                {
                    while (y < n && (nums[y] < nums[x] + k || y <= x))
                    {
                        y++;
                    }
                    if (y < n && nums[y] == nums[x] + k)
                    {
                        res++;
                    }
                }
            }
            return res;
        }

    }
}
