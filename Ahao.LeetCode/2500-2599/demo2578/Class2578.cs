﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2578
{
    internal class Class2578
    {

        public int SplitNum(int num)
        {
            char[] stnum = num.ToString().ToCharArray();
            Array.Sort(stnum);
            int num1 = 0, num2 = 0;
            for (int i = 0; i < stnum.Length; ++i)
            {
                if (i % 2 == 0)
                {
                    num1 = num1 * 10 + (stnum[i] - '0');
                }
                else
                {
                    num2 = num2 * 10 + (stnum[i] - '0');
                }
            }
            return num1 + num2;
        }


    }
}
