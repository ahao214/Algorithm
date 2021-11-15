using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1365. 有多少小于当前数字的数字
    /// </summary>
    public class SmallerNumbersThanCurrent
    {
        public int[] Method(int[] nums)
        {
            //定义一个新的数组
            int[] result = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
                int count = 0;
                for (int j = 0; j < nums.Length; j++)
                {
                    if (nums[j] < nums[i] && j != i)
                    {
                        count++;
                    }
                }
                result[i] = count;
            }
            return result;
        }
    }
}
