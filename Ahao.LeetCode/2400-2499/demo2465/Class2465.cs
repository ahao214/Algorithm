using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2465
{
    public class Class2465
    {
        public int DistinctAverages(int[] nums)
        {
            ISet<int> st = new HashSet<int>();
            Array.Sort(nums);
            for (int i = 0, j = nums.Length - 1; i < j; i++, j--)
            {
                st.Add(nums[i] + nums[j]);
            }
            return st.Count();

        }
    }
}
