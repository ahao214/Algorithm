﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2029
{
    public class Class2029
    {
        public bool StoneGameIX(int[] stones)
        {
            int cnt0 = 0, cnt1 = 0, cnt2 = 0;
            foreach (int val in stones)
            {
                int type = val % 3;
                if (type == 0)
                {
                    ++cnt0;
                }
                else if (type == 1)
                {
                    ++cnt1;
                }
                else
                {
                    ++cnt2;
                }
            }
            if (cnt0 % 2 == 0)
            {
                return cnt1 >= 1 && cnt2 >= 1;
            }
            return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
        }
    }
}
