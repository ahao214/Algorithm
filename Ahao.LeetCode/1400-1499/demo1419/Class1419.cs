﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1419
{
    public class Class1419
    {

        public int MinNumberOfFrogs(string croakOfFrogs)
        {
            if (croakOfFrogs.Length % 5 != 0)
            {
                return -1;
            }
            int res = 0, frogNum = 0;
            int[] cnt = new int[4];
            IDictionary<char, int> dictionary = new Dictionary<char, int>() {
            {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}
        };
            foreach (char c in croakOfFrogs)
            {
                int t = dictionary[c];
                if (t == 0)
                {
                    cnt[t]++;
                    frogNum++;
                    if (frogNum > res)
                    {
                        res = frogNum;
                    }
                }
                else
                {
                    if (cnt[t - 1] == 0)
                    {
                        return -1;
                    }
                    cnt[t - 1]--;
                    if (t == 4)
                    {
                        frogNum--;
                    }
                    else
                    {
                        cnt[t]++;
                    }
                }
            }
            if (frogNum > 0)
            {
                return -1;
            }
            return res;
        }


    }
}
