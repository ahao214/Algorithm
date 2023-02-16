using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2341
{
    public class Class2341
    {
        public int[] NumberOfPairs(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int pairCount = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (!dic.ContainsKey(nums[i]))
                {
                    dic.Add(nums[i], 1);
                }
                else
                {
                    pairCount += 1;
                    dic.Remove(nums[i]);
                }
            }
            return new int[] { pairCount, dic.Count };
        }

    }
}
