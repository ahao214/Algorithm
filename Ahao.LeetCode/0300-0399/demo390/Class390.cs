using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo390
{
    /// <summary>
    /// 390. 消除游戏
    /// </summary>
    public class Class390
    {
        public int LastRemaining(int n)
        {
            if (n == 1)
            {
                return 1;
            }
            int size = n / 2;
            int dis = 2;
            int start = 2;
            int flag = 0;
            while (size > 1)
            {
                if (flag % 2 == 0)
                {
                    start = (size % 2 == 0) ? start : start + dis;
                }
                else
                {
                    start = start + dis;
                }
                size = size / 2;
                dis = dis * 2;
                ++flag;
            }
            return start;
        }
    }
}
