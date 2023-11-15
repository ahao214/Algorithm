using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2656
{
    internal class Class2656
    {
        public int MaximizeSum(int[] nums, int k)
        {
            int maxValue = nums.Max();
            return (2 * maxValue + k - 1) * k / 2;
        }



    }
}
