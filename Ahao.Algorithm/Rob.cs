using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 198.打家劫舍
    /// </summary>
    public class Rob
    {
        public int Method(int[] nums)
        {          
            if (nums.Length == 0)
            {
                return 0;
            }

            int currentMoney = 0;
            int previousMoney = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                int temp = currentMoney;               
                currentMoney = Math.Max(currentMoney, previousMoney + nums[i]);
                previousMoney = temp;
            }
            return currentMoney;

           
        }
    }
}
