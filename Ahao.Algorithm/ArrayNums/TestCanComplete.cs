using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 确定出发加油站问题
    /// </summary>
    public class TestCanComplete
    {
        public static int CanComplete(int[] gas, int[] cost)
        {
            int total = 0;
            int j = -1;
            for (int i = 0, sum = 0; i < gas.Length; i++)
            {
                sum += gas[i] - cost[i];
                total += gas[i] - cost[i];
                if (sum < 0)
                {
                    j = i;  //不断更新，最后一次sum<0的下标j
                    sum = 0;    //清空sum重新从i+1开始判断
                }
            }
            //只要总汽油量要大于总的消耗量，那么肯定是有解的，不用构成环来判断
            return total >= 0 ? j + 1 : -1;
        }

    }
}
