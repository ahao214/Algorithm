﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1281
{
    public class Class1281
    {

        public int SubtractProductAndSum(int n)
        {
            int mul = 1, sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                mul *= digit;
                sum += digit;
                n /= 10;
            }
            return mul - sum;
        }


    }
}
