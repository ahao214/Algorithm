using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 16. 最接近的三数之和
    /// </summary>
    public class ThreeSumClosest
    {
        public int Method(int[] nums, int target)
        {
            int res = 0;
            int difference = int.MaxValue;
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    for (int k = j + 1; k < nums.Length; k++)
                    {
                        if(Abs(nums[i]+nums[j]+nums[k]-target)<difference)
                        {
                            difference = Abs(nums[i] + nums[j] + nums[k] - target);
                            res = nums[i] + nums[j] + nums[k];
                        }
                    }
                }
            }
            return res;
        }

        public static int Abs(int a)
        {
            if (a > 0)
            {
                return a;
            }
            return -a;
        }
    }
}
