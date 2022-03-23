using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo747
{
    public class Class747
    {
        public int DominantIndex(int[] nums)
        {
            int size = nums.Length;
            if (size == 1)
            {
                return 0;
            }

            int maxValue = nums.Max();
            int halfValue = maxValue / 2;
            int index = -1;
            for (int i = 0; i < size; i++)
            {
                if (maxValue == nums[i])
                    index = i;
            }
            for (int i = 0; i < size; i++)
            {
                if (nums[i] > halfValue && nums[i] != maxValue)
                {
                    return -1;
                }
            }
            return index;
        }
    }
}
