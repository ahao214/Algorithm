﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Other
{
    /*
     有m个同样的苹果和n个同样的盘子
    比如：5个苹果和3个盘子
    1,3,1和1,1,3和3,1,1,的放置方法是相同，被认为是一种方法
    如上所述，求有多少种放置方法
     */
    public class SplitApple
    {
        /// <summary>
        /// 盘子装苹果
        /// </summary>
        /// <param name="apples">苹果数量</param>
        /// <param name="plates">盘子数量</param>
        /// <returns></returns>
        public int Way(int apples, int plates)
        {
            if (apples == 0)
            {
                return 1;
            }
            if (plates == 0)
            {
                return 0;
            }
            //多余的盘子摔碎
            if (apples < plates)
            {
                return Way(apples, apples);
            }

            //apples>=plates
            // 1.所有的盘子全部使用，方法数a
            int a = Way(apples - plates, plates);
            // 2.只使用部分的盘子，方法数b
            int b = Way(apples, plates - 1);
            return a + b;
        }

        //动态规划方法
        public int[,] map = new int[101, 101];
        public int Ways(int apples, int plates)
        {
            for (int i = 0; i <= apples; i++)
            {
                for (int j = 0; j <= plates; j++)
                {
                    map[i, j] = -1;
                }
            }
            return process(apples, plates);
        }

        private int process(int apples, int plates)
        {
            if (map[apples, plates] != -1)
            {
                return map[apples, plates];
            }

            int ans = 0;
            if (apples == 0)
            {
                ans = 1;
            }
            else if (plates == 0)
            {
                ans = 0;
            }
            else if (apples < plates)
            {
                ans = Ways(apples, apples);
            }
            else
            {
                int a = Ways(apples - plates, plates);
                int b = Ways(apples, plates - 1);
                ans = a + b;
            }
            map[apples, plates] = ans;
            return ans;
        }

    }
}
