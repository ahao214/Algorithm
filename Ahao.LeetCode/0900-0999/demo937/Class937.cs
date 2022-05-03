﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo937
{
    public class Class937
    {
        public string[] ReorderLogFiles(string[] logs)
        {
            int length = logs.Length;
            Pair[] arr = new Pair[length];
            for (int i = 0; i < length; i++)
            {
                arr[i] = new Pair(logs[i], i);
            }
            Array.Sort(arr, (a, b) => LogCompare(a, b));
            string[] reordered = new string[length];
            for (int i = 0; i < length; i++)
            {
                reordered[i] = arr[i].log;
            }
            return reordered;
        }

        public int LogCompare(Pair pair1, Pair pair2)
        {
            string log1 = pair1.log, log2 = pair2.log;
            int index1 = pair1.index, index2 = pair2.index;
            string[] split1 = log1.Split(" ", 2);
            string[] split2 = log2.Split(" ", 2);
            bool isDigit1 = char.IsDigit(split1[1][0]);
            bool isDigit2 = char.IsDigit(split2[1][0]);
            if (isDigit1 && isDigit2)
            {
                return index1 - index2;
            }
            if (!isDigit1 && !isDigit2)
            {
                int sc = split1[1].CompareTo(split2[1]);
                if (sc != 0)
                {
                    return sc;
                }
                return split1[0].CompareTo(split2[0]);
            }
            return isDigit1 ? 1 : -1;
        }


        public class Pair
        {
            public string log;
            public int index;

            public Pair(string log, int index)
            {
                this.log = log;
                this.index = index;
            }
        }
    }
}
