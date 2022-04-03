using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099.demo6055
{
    /*
     6055. 转化时间需要的最少操作数 显示英文描述 
题目难度Easy
给你两个字符串 current 和 correct ，表示两个 24 小时制时间 。

24 小时制时间 按 "HH:MM" 进行格式化，其中 HH 在 00 和 23 之间，而 MM 在 00 和 59 之间。最早的 24 小时制时间为 00:00 ，最晚的是 23:59 。

在一步操作中，你可以将 current 这个时间增加 1、5、15 或 60 分钟。你可以执行这一操作 任意 次数。

返回将 current 转化为 correct 需要的 最少操作数 。
     */
    public class Class6055
    {
        public int ConvertTime(string current, string correct)
        {
            int sumCurrent = Convert.ToInt32(current.Substring(0, 2)) * 60 + Convert.ToInt32(current.Substring(3));
            int sumCorrect = Convert.ToInt32(correct.Substring(0, 2)) * 60 + Convert.ToInt32(correct.Substring(3));
            int cnt = 0;

            int time = sumCorrect - sumCurrent;
            while (time > 0)
            {
                if (time >= 60)
                {
                    cnt += time / 60;
                    time %= 60;
                }
                else if (time >= 15)
                {
                    cnt += time / 15;
                    time %= 15;
                }
                else if (time >= 5)
                {
                    cnt += time / 5;
                    time %= 5;
                }
                else
                {
                    cnt += time;
                    time %= 1;
                }
            }

            return cnt;
        }
    }
}
