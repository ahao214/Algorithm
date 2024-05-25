using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999._2903
{
    internal class Class2903
    {
        public int[] FindIndices(int[] nums, int indexDifference, int valueDifference)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i; j < nums.Length; j++)
                {
                    if (j - i >= indexDifference && Math.Abs(nums[j] - nums[i]) >= valueDifference)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return new int[] { -1, -1 };
        }


        public int[] FindIndices2(int[] nums, int indexDifference, int valueDifference)
        {
            int minIndex = 0, maxIndex = 0;
            for (int j = indexDifference; j < nums.Length; j++)
            {
                int i = j - indexDifference;
                if (nums[i] < nums[minIndex])
                {
                    minIndex = i;
                }
                if (nums[j] - nums[minIndex] >= valueDifference)
                {
                    return new int[] { minIndex, j };
                }
                if (nums[i] > nums[maxIndex])
                {
                    maxIndex = i;
                }
                if (nums[maxIndex] - nums[j] >= valueDifference)
                {
                    return new int[] { maxIndex, j };
                }
            }
            return new int[] { -1, -1 };
        }



    }
}
