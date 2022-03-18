using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1705
{
    /// <summary>
    /// 1705. 吃苹果的最大数目
    /// </summary>
    public class Class1705
    {
        public int eatenApples(int[] apples, int[] days)
        {
            // 第i天坏的果子为arr[i]个
            int[] arr = new int[40001];
            //当前最晚坏掉的果子在第maxDay天坏掉
            //剩余果子中最早坏掉的在第minDay天坏掉
            int maxDay = 0;
            int minDay = 0;
            int ans = 0;
            for (int i = 0; i < 40000; ++i)
            {
                //扔掉已经坏掉的果子
                if (minDay <= i)
                {
                    minDay = i + 1;
                }
                //把当前天的果子更新到arr中
                if (i < apples.Length && apples[i] > 0)
                {
                    //当前果子在cur天坏掉
                    int cur = i + days[i];
                    arr[cur] += apples[i];
                    minDay = Math.Min(minDay, cur);
                    maxDay = Math.Max(maxDay, cur);
                }
                while (arr[minDay] == 0 && minDay <= maxDay)
                {
                    ++minDay;
                }
                //minDay<=maxDay时，说明有未坏掉的果子，那就吃一个，更新ans
                if (minDay <= maxDay)
                {
                    --arr[minDay];
                    ++ans;
                }
                else if (i > apples.Length)
                {
                    //此时没有果子可以吃，树上的也已经摘完，可以结束了
                    return ans;
                }
            }
            return ans;
        }
    }
}
