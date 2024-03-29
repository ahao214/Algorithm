﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2591
{
    internal class Class2591
    {
        public int DistMoney(int money, int children)
        {
            int res = -1;
            if (money < children)
            {
                return res;
            }
            else if (money > 8 * children)
            {
                res = children - 1;
            }

            else if (money == 8 * children - 4)
            {
                res = children - 2;
            }
            else
            {
                res = (money - children) / 7;
            }

            return res;
        }



        public int DistMoney2(int money, int children)
        {
            if (money < children)
            {
                return -1;
            }
            money -= children;
            int cnt = Math.Min(money / 7, children);
            money -= cnt * 7;
            children -= cnt;
            if ((children == 0 && money > 0) || (children == 1 && money == 3))
            {
                cnt--;
            }
            return cnt;
        }

    }
}
