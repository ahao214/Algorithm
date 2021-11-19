using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC176
{
    /// <summary>
    /// NC176 打家劫舍(一)
    /// </summary>
    public class Class176
    {
        public int rob(List<int> nums)
        {
            if (nums.Count == 0)
            {
                return 0;
            }

            int curMoney = 0;
            int preMoney = 0;
            for (int i = 0; i < nums.Count; i++)
            {
                int tmp = curMoney;
                curMoney = Math.Max(curMoney, preMoney + nums[i]);
                preMoney = tmp;
            }
            return curMoney;
        }
    }
}
