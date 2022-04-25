using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo398
{
    public class Class398
    {

        Dictionary<int, IList<int>> pos;
        Random random;

        public Class398(int[] nums)
        {
            pos = new Dictionary<int, IList<int>>();
            random = new Random();
            for (int i = 0; i < nums.Length; ++i)
            {
                if (!pos.ContainsKey(nums[i]))
                {
                    pos.Add(nums[i], new List<int>());
                }
                pos[nums[i]].Add(i);
            }
        }

        public int Pick(int target)
        {
            IList<int> indices = pos[target];
            return indices[random.Next(indices.Count)];
        }

    }
}
