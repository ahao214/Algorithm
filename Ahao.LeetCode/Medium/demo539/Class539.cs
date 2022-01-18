using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo539
{
    /*
     539. 最小时间差
    给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
     */
    public class Class539
    {
        public int FindMinDifference(IList<string> timePoints)
        {
            timePoints = timePoints.OrderBy(x => x).ToList();
            int res = int.MaxValue;
            int zeroMinutes = getMinutes(timePoints[0]);
            int preMinutes = zeroMinutes;
            for (int i = 1; i < timePoints.Count; ++i)
            {
                int minutes = getMinutes(timePoints[i]);
                res = Math.Min(res, minutes - preMinutes); // 相邻时间的时间差
                preMinutes = minutes;
            }
            res = Math.Min(res, zeroMinutes + 1440 - preMinutes); // 首尾时间的时间差
            return res;
        }

        public int getMinutes(string t)
        {
            return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
        }

    }
}
