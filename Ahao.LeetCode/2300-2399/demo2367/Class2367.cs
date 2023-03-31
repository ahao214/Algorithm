using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2367
{
    public class Class2367
    {
        public int ArithmeticTriplets(int[] nums, int diff)
        {
            int res = 0;
            ISet<int> st = new HashSet<int>();
            foreach (var item in nums)
            {
                st.Add(item);
            }
            foreach (var item in nums)
            {
                if (st.Contains(item + diff) && st.Contains(item + 2 * diff))
                {
                    res++;
                }
            }
            return res;
        }


        public int ArithmeticTriplets2(int[] nums, int diff)
        {
            int ans = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] - nums[i] != diff)
                    {
                        continue;
                    }
                    for (int k = j + 1; k < n; k++)
                    {
                        if (nums[k] - nums[j] == diff)
                        {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }

    }
}
