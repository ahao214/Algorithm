using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 674.最长连续递增序列
    /// </summary>
    public class FindLengthOfLCIS
    {
        public int Method(int[] nums)
        {
            int num = 0, temp = 1, count = nums.Length;
            bool flag = true;
            if (count == 0)
            {
                return 0;
            }

            for (int i = 1; i < count; i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    flag = true;
                    temp++;
                }
                else
                {
                    flag = false;
                    num = Math.Max(num, temp);
                    temp = 1;
                }
            }
            return Math.Max(num, temp);
        }
    }
}
