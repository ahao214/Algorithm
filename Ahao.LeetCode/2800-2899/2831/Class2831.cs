using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2831
{
    public class Class2831
    {
        public int LongestEqualSubarray(IList<int> nums, int k)
        {
            int n = nums.Count;
            IDictionary<int, IList<int>> pos = new Dictionary<int, IList<int>>();
            for (int i = 0; i < n; i++)
            {
                pos.TryAdd(nums[i], new List<int>());
                pos[nums[i]].Add(i);
            }
            int ans = 0;
            foreach (IList<int> vec in pos.Values)
            {
                for (int i = 0, j = 0; i < vec.Count; i++)
                {
                    /* 缩小窗口，直到不同元素数量小于等于 k */
                    while (vec[i] - vec[j] - (i - j) > k)
                    {
                        j++;
                    }
                    ans = Math.Max(ans, i - j + 1);
                }
            }
            return ans;
        }


    }


}
