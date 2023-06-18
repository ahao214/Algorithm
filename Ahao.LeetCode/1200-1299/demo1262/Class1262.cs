﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1262
{
    public class Class1262
    {

        public int MaxSumDivThree(int[] nums)
        {
            // 使用 v[0], v[1], v[2] 分别表示 a, b, c
            IList<int>[] v = new IList<int>[3];
            for (int i = 0; i < 3; ++i)
            {
                v[i] = new List<int>();
            }
            foreach (int num in nums)
            {
                v[num % 3].Add(num);
            }
            ((List<int>)v[1]).Sort((a, b) => b - a);
            ((List<int>)v[2]).Sort((a, b) => b - a);

            int ans = 0;
            int lb = v[1].Count, lc = v[2].Count;
            for (int cntb = lb - 2; cntb <= lb; ++cntb)
            {
                if (cntb >= 0)
                {
                    for (int cntc = lc - 2; cntc <= lc; ++cntc)
                    {
                        if (cntc >= 0 && (cntb - cntc) % 3 == 0)
                        {
                            ans = Math.Max(ans, GetSum(v[1], 0, cntb) + GetSum(v[2], 0, cntc));
                        }
                    }
                }
            }
            return ans + GetSum(v[0], 0, v[0].Count);
        }

        public int GetSum(IList<int> list, int start, int end)
        {
            int sum = 0;
            for (int i = start; i < end; ++i)
            {
                sum += list[i];
            }
            return sum;
        }


    }
}
