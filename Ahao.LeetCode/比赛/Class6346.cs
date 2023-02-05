using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6346. 打家劫舍 IV 

沿街有一排连续的房屋。每间房屋内都藏有一定的现金。现在有一位小偷计划从这些房屋中窃取现金。

由于相邻的房屋装有相互连通的防盗系统，所以小偷 不会窃取相邻的房屋 。

小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额 。

给你一个整数数组 nums 表示每间房屋存放的现金金额。形式上，从左起第 i 间房屋中放有 nums[i] 美元。

另给你一个整数数组 k ，表示窃贼将会窃取的 最少 房屋数。小偷总能窃取至少 k 间房屋。

返回小偷的 最小 窃取能力。
     */
    public class Class6346
    {
        public int MinCapability(int[] nums, int k)
        {
            int minValue = 0;
            int n = nums.Length;
            if (n == 0)
                return minValue;
            int currentMoney = 0;
            int previousMoney = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                int temp = currentMoney;
                currentMoney = Math.Max(currentMoney, previousMoney + nums[i]);
                previousMoney = temp;
            }


            return minValue;
        }
    }
}
