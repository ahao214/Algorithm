using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 215. 数组中的第K个最大元素
    /// </summary>
    public class FindKthLargest
    {
        public int Method(int[] nums, int k)
        {
            int result = 0;

            List<int> lstNum = new List<int>();
            Array.Sort(nums);
            for (int i = 0; i < nums.Length; i++)
            {
                Console.WriteLine(nums[i]);
            }


            return result;
        }
    }
}
