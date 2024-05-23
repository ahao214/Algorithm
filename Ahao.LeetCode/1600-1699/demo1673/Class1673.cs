﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1673
{
    public class Class1673
    {
        public int[] MostCompetitive(int[] nums, int k)
        {
            Stack<int> stack = new Stack<int>();
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                while (stack.Count > 0 && n - i + stack.Count > k && stack.Peek() > nums[i])
                {
                    stack.Pop();
                }
                stack.Push(nums[i]);
            }
            int[] res = new int[k];
            while (stack.Count > k)
            {
                stack.Pop();
            }
            for (int i = k - 1; i >= 0; i--)
            {
                res[i] = stack.Pop();
            }
            return res;
        }

    }
}
