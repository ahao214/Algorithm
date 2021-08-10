using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 283. 移动零
    /// </summary>
    public class MoveZeroes
    {
        public void Method(int[] nums)
        {
            int j = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != 0)
                {
                    if (i != j)
                    {
                        nums[j] = nums[i];
                        nums[i] = 0;
                    }
                    j++;
                }
            }
        }
    }
}
