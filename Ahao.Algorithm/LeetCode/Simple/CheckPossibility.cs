using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 665. 非递减数列
    /// </summary>
    public class CheckPossibility
    {
        public bool Method(int[] nums)
        {
            var result = true;
            var isTemp = true;
            var newNums = nums.ToArray();
            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    nums[i] = nums[i + 1];
                    newNums[i + 1] = newNums[i];
                    break;
                }
            }

            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    result = false;
                    break;
                }
            }

            for (int i = 0; i < newNums.Length - 1; i++)
            {
                if (newNums[i] > newNums[i + 1])
                {
                    isTemp = false;
                }
            }
            return result || isTemp;
        }
    }
}
