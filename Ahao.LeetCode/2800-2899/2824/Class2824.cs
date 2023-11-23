using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2824
{
    public class Class2824
    {
        public int CountPairs(IList<int> nums, int target)
        {
            int res = 0;
            for (int i = 0; i < nums.Count; i++)
            {
                for (int j = i + 1; j < nums.Count; j++)
                {
                    if (nums[i] + nums[j] < target)
                        res++;
                }
            }
            return res;
        }



    }
}
