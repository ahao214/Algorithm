﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
    6348. 从数量最多的堆取走礼物 
给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：

选择礼物数量最多的那一堆。
如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
返回在 k 秒后剩下的礼物数量。
     */
    public class Class6348
    {
        public long PickGifts(int[] gifts, int k)
        {
            int n = gifts.Length;
            long res = 0;
            while (k > 0)
            {
                Array.Sort(gifts);
                k--;
                int val = Convert.ToInt32(Math.Floor(Math.Sqrt(gifts[n - 1])));
                gifts[n - 1] = val;
            }
            for (int i = 0; i < n; i++)
            {
                res += gifts[i];
            }
            return res;
        }

    }
}
