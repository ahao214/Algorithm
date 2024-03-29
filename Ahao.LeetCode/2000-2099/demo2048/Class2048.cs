﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2048
{
    public class Class2048
    {

        private static int[] balance = new int[] {
        1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444,
        14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332,
        33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555,
        122333, 123233, 123323, 123332, 132233, 132323, 132332,
        133223, 133232, 133322, 155555, 212333, 213233, 213323,
        213332, 221333, 223133, 223313, 223331, 224444, 231233,
        231323, 231332, 232133, 232313, 232331, 233123, 233132,
        233213, 233231, 233312, 233321, 242444, 244244, 244424,
        244442, 312233, 312323, 312332, 313223, 313232, 313322,
        321233, 321323, 321332, 322133, 322313, 322331, 323123,
        323132, 323213, 323231, 323312, 323321, 331223, 331232,
        331322, 332123, 332132, 332213, 332231, 332312, 332321,
        333122, 333212, 333221, 422444, 424244, 424424, 424442,
        442244, 442424, 442442, 444224, 444242, 444422, 515555,
        551555, 555155, 555515, 555551, 666666, 1224444
    };

        public int NextBeautifulNumber(int n)
        {
            int i = Array.BinarySearch(balance, n + 1);
            if (i < 0)
            {
                i = -i - 1;
            }
            return balance[i];
        }



        public int NextBeautifulNumber2(int n)
        {
            for (int i = n + 1; i <= 1224444; i++)
            {
                if (IsBalance(i))
                {
                    return i;
                }
            }
            return -1;
        }

        private bool IsBalance(int x)
        {
            int[] count = new int[10];
            while (x > 0)
            {
                count[x % 10]++;
                x /= 10;
            }
            for (int i = 0; i < 10; i++)
            {
                if (count[i] > 0 && count[i] != i)
                {
                    return false;
                }
            }
            return true;
        }


    }
}
