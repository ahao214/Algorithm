﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1238
{
    public class Class1238
    {
        /// <summary>
        /// 归纳法
        /// </summary>
        /// <param name="n"></param>
        /// <param name="start"></param>
        /// <returns></returns>
        public IList<int> CircularPermutation(int n, int start)
        {
            IList<int> ret = new List<int>();
            ret.Add(start);
            for (int i = 1; i <= n; i++)
            {
                int m = ret.Count;
                for (int j = m - 1; j >= 0; j--)
                {
                    ret.Add(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
                }
            }
            return ret;
        }

        /// <summary>
        /// 公式法
        /// </summary>
        /// <param name="n"></param>
        /// <param name="start"></param>
        /// <returns></returns>
        public IList<int> CircularPermutation2(int n, int start)
        {
            IList<int> ret = new List<int>();
            for (int i = 0; i < 1 << n; i++)
            {
                ret.Add((i >> 1) ^ i ^ start);
            }
            return ret;
        }


        public IList<int> CircularPermutation3(int n, int start)
        {
            int[] arr = new int[1 << n];
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = i ^ i >> 1;
                arr[i] = arr[i] ^ start;
            }
            return arr;
        }

    }
}
