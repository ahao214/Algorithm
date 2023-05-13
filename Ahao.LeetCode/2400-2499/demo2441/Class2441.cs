using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2441
{
    public class Class2441
    {
        public int FindMaxK(int[] nums)
        {
            int res = -1;
            Array.Sort(nums);
            int left = 0;
            int right = nums.Length - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == 0)
                {
                    return nums[right];
                }
                else if (nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return -1;

        }


        public int FindMaxK2(int[] nums)
        {
            int k = -1;
            foreach (int x in nums)
            {
                foreach (int y in nums)
                {
                    if (-x == y)
                    {
                        k = Math.Max(k, x);
                    }
                }
            }
            return k;
        }



        public int FindMaxK3(int[] nums)
        {
            int k = -1;
            ISet<int> set = new HashSet<int>();
            foreach (int x in nums)
            {
                set.Add(x);
            }
            foreach (int x in nums)
            {
                if (set.Contains(-x))
                {
                    k = Math.Max(k, x);
                }
            }
            return k;
        }


        public int FindMaxK4(int[] nums)
        {
            Array.Sort(nums);
            for (int i = 0, j = nums.Length - 1; i < j; j--)
            {
                while (i < j && nums[i] < -nums[j])
                {
                    i++;
                }
                if (nums[i] == -nums[j])
                {
                    return nums[j];
                }
            }
            return -1;
        }



    }
}
