using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1480. 一维数组的动态和
    /// </summary>
    public class RunningSum
    {
        public int[] Method(int[] nums)
        {
            int len = nums.Length;
            int[] newNums = new int[len];
            int temp = nums[0];
            newNums[0] = nums[0];
            for (int i = 1; i < len; i++)
            {
                newNums[i] = temp + nums[i];
                temp += nums[i];
            }
            return newNums;
        }
    }
}
