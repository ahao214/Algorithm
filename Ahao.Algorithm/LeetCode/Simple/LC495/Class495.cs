using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 495. 提莫攻击
    /// </summary>
    public class Class495
    {
        public int FindPoisonedDuration(int[] timeSeries, int duration)
        {
            if (timeSeries == null || timeSeries.Length == 0 || duration == 0)
            {
                return 0;
            }
            int res = 0;
            int expired = 0;
            for (int i = 0; i < timeSeries.Length; i++)
            {
                if (timeSeries[i] >= expired)
                {
                    res += duration;
                }
                else
                {
                    res += timeSeries[i] + duration - expired;
                }
                expired = timeSeries[i] + duration;
            }
            return res;
        }
    }
}
