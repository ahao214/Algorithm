using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1464
{
    public class Class1464
    {
        public int MaxProduct(int[] nums)
        {
            Array.Sort(nums);
            return (nums[nums.Length - 1] - 1) * (nums[nums.Length - 2] - 1);
        }

        public int MaxProduct2(int[] nums)
        {
            int a = nums[0], b = nums[1];
            if (a < b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            for (int i = 2; i < nums.Length; i++)
            {
                if (nums[i] > a)
                {
                    b = a;
                    a = nums[i];
                }
                else if (nums[i] > b)
                {
                    b = nums[i];
                }
            }
            return (a - 1) * (b - 1);
        }


    }
}
