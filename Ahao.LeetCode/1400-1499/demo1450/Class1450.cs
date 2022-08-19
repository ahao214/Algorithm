using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1450
{
    public class Class1450
    {
        //枚举
        public int BusyStudent(int[] startTime, int[] endTime, int queryTime)
        {
            int n = startTime.Length;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                {
                    ans++;
                }
            }
            return ans;
        }

        //差分数组
        public int BusyStudent2(int[] startTime, int[] endTime, int queryTime)
        {
            int n = startTime.Length;
            int maxEndTime = endTime.Max();
            if (queryTime > maxEndTime)
            {
                return 0;
            }
            int[] cnt = new int[maxEndTime + 2];
            for (int i = 0; i < n; i++)
            {
                cnt[startTime[i]]++;
                cnt[endTime[i] + 1]--;
            }
            int ans = 0;
            for (int i = 0; i <= queryTime; i++)
            {
                ans += cnt[i];
            }
            return ans;
        }


    }
}
