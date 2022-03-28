﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1405
{
    public class Class1405
    {
        public string LongestDiverseString(int a, int b, int c)
        {
            StringBuilder res = new StringBuilder();
            Pair[] arr = { new Pair(a, 'a'), new Pair(b, 'b'), new Pair(c, 'c') };

            while (true)
            {
                Array.Sort(arr, (p1, p2) => p2.Freq - p1.Freq);
                bool hasNext = false;
                foreach (Pair pair in arr)
                {
                    if (pair.Freq <= 0)
                    {
                        break;
                    }
                    int m = res.Length;
                    if (m >= 2 && res[m - 2] == pair.Ch && res[m - 1] == pair.Ch)
                    {
                        continue;
                    }
                    hasNext = true;
                    res.Append(pair.Ch);
                    pair.Freq--;
                    break;
                }
                if (!hasNext)
                {
                    break;
                }
            }

            return res.ToString();
        }
    }

    class Pair
    {
        public int Freq
        {
            get; set;
        }
        public char Ch
        {
            get; set;
        }

        public Pair(int Freq, char Ch)
        {
            this.Freq = Freq;
            this.Ch = Ch;
        }
    }
}
