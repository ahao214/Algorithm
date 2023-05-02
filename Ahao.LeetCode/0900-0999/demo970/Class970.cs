﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo970
{
    public class Class970
    {
        public IList<int> PowerfulIntegers(int x, int y, int bound)
        {
            ISet<int> set = new HashSet<int>();
            int value1 = 1;
            for (int i = 0; i < 21; i++)
            {
                int value2 = 1;
                for (int j = 0; j < 21; j++)
                {
                    int value = value1 + value2;
                    if (value <= bound)
                    {
                        set.Add(value);
                    }
                    else
                    {
                        break;
                    }
                    value2 *= y;
                }
                if (value1 > bound)
                {
                    break;
                }
                value1 *= x;
            }
            return new List<int>(set);
        }


    }
}
