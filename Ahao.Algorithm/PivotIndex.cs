using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 724. 寻找数组的中心索引
    /// </summary>
    public class PivotIndex
    {
        public int Method(int[] nums)
        {
            int result = -1;
            if (nums.Length == 0)
            {
                return result;
            }

            int allSum = 0;
            int leftSum = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                allSum += nums[i];
            }
            for (int j = 0; j < nums.Length; j++)
            {
                if (j != 0)
                {
                    leftSum += nums[j - 1];
                }
                allSum -= nums[j];
                if (leftSum == allSum)
                {
                    //找到第一个就返回
                    result = j;
                    break;
                }
            }

            return result;
        }
    }
}
