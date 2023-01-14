﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1819
{
    public class Class1819
    {
        public int CountDifferentSubsequenceGCDs(int[] nums)
        {
            int maxVal = nums.Max();
            bool[] occured = new bool[maxVal + 1];
            foreach (int num in nums)
            {
                occured[num] = true;
            }
            int ans = 0;
            for (int i = 1; i <= maxVal; i++)
            {
                int subGcd = 0;
                for (int j = i; j <= maxVal; j += i)
                {
                    if (occured[j])
                    {
                        if (subGcd == 0)
                        {
                            subGcd = j;
                        }
                        else
                        {
                            subGcd = GCD(subGcd, j);
                        }
                        if (subGcd == i)
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
            return ans;
        }

        public int GCD(int num1, int num2)
        {
            while (num2 != 0)
            {
                int temp = num1;
                num1 = num2;
                num2 = temp % num2;
            }
            return num1;
        }
    }
}
