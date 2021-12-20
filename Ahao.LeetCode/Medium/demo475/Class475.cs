using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo475
{
    /// <summary>
    /// 475. 供暖器
    /// </summary>
    public class Class475
    {
        public int FindRadius(int[] houses, int[] heaters)
        {
            int result = 0;
            Array.Sort(heaters);
            for (int i = 0; i < houses.Length; i++)
            {
                int ans = int.MaxValue;
                for (int j = 0; j < heaters.Length; j++)
                {
                    int curDis = Math.Abs(houses[i] - heaters[j]);
                    ans = Math.Min(curDis, ans);
                }
                result = Math.Max(result, ans);
            }
            return result;
        }
    }
}
