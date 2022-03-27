﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo393
{
    public class Class393
    {
        const int MASK1 = 1 << 7;
        const int MASK2 = (1 << 7) + (1 << 6);

        public bool ValidUtf8(int[] data)
        {
            int m = data.Length;
            int index = 0;
            while (index < m)
            {
                int num = data[index];
                int n = GetBytes(num);
                if (n < 0 || index + n > m)
                {
                    return false;
                }
                for (int i = 1; i < n; i++)
                {
                    if (!IsValid(data[index + i]))
                    {
                        return false;
                    }
                }
                index += n;
            }
            return true;
        }

        public int GetBytes(int num)
        {
            if ((num & MASK1) == 0)
            {
                return 1;
            }
            int n = 0;
            int mask = MASK1;
            while ((num & mask) != 0)
            {
                n++;
                if (n > 4)
                {
                    return -1;
                }
                mask >>= 1;
            }
            return n >= 2 ? n : -1;
        }

        public bool IsValid(int num)
        {
            return (num & MASK2) == MASK1;
        }

    }
}
