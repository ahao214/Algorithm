﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo849
{
    public class Class849
    {
        public int MaxDistToClosest(int[] seats)
        {
            int i = 0;
            int j = seats.Length - 1;
            int count1 = 0;
            int count2 = 0;
            while (seats[i] == 0)
            {
                count1++;
                i++;
            }
            while (seats[j] == 0)
            {
                count2++;
                j--;
            }
            int count3 = 0;
            int countSum = 0;
            for (int k = i + 1; k <= j; k++)
            {
                if (seats[k] == 0)
                {
                    count3++;
                }
                else
                {
                    countSum = Math.Max(countSum, count3);
                    count3 = 0;
                }
            }

            return Math.Max(Math.Max(count1, count2), (countSum + 1) / 2);

        }




        public int MaxDistToClosest2(int[] seats)
        {
            int res = 0;
            int l = 0;
            while (l < seats.Length && seats[l] == 0)
            {
                ++l;
            }
            res = Math.Max(res, l);
            while (l < seats.Length)
            {
                int r = l + 1;
                while (r < seats.Length && seats[r] == 0)
                {
                    ++r;
                }
                if (r == seats.Length)
                {
                    res = Math.Max(res, r - l - 1);
                }
                else
                {
                    res = Math.Max(res, (r - l) / 2);
                }
                l = r;
            }
            return res;
        }


    }
}
