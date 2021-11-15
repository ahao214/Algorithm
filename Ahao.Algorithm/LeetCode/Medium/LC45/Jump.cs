using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 45.跳跃游戏(2)
    /// </summary>
    public class Jump
    {
        public int Method(int[] nums)
        {
            nums[nums.Length - 1] = 0;
            for (int i = nums.Length - 2; i >= 0; i--)
            {
                if (i + nums[i] >= nums.Length)
                {
                    nums[i] = 1;
                }
                else
                {
                    if (nums[i]==0)
                    {
                        nums[i] = int.MaxValue;
                    }
                    else
                    {
                        var min = nums.Skip(i + 1).Take(nums[i]).Min();
                        nums[i] = min == int.MaxValue ? int.MaxValue : min + 1;
                    }
                }
            }
            return nums[0];
        }
    }
}
