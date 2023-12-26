﻿using System;
using System.Collections.Generic;

namespace Ahao.LeetCode.Hard.demo1349
{
    public class Class1349
    {
        IDictionary<int, int> memo = new Dictionary<int, int>();

        public int MaxStudents(char[][] seats)
        {
            int m = seats.Length, n = seats[0].Length;
            int mx = 0;
            for (int i = 0; i < 1 << n; i++)
            {
                mx = Math.Max(mx, DP(seats, m - 1, i));
            }
            return mx;
        }

        public int DP(char[][] seats, int row, int status)
        {
            int n = seats[0].Length;
            int key = (row << n) + status;
            if (!memo.ContainsKey(key))
            {
                if (!IsSingleRowCompliant(seats, status, n, row))
                {
                    memo.Add(key, int.MinValue);
                    return int.MinValue;
                }
                int students = BitCount(status);
                if (row == 0)
                {
                    memo.Add(key, students);
                    return students;
                }
                int mx = 0;
                for (int upperRowStatus = 0; upperRowStatus < 1 << n; upperRowStatus++)
                {
                    if (IsCrossRowsCompliant(status, upperRowStatus, n))
                    {
                        mx = Math.Max(mx, DP(seats, row - 1, upperRowStatus));
                    }
                }
                memo.Add(key, students + mx);
            }
            return memo[key];
        }

        public bool IsSingleRowCompliant(char[][] seats, int status, int n, int row)
        {
            for (int j = 0; j < n; j++)
            {
                if (((status >> j) & 1) == 1)
                {
                    if (seats[row][j] == '#')
                    {
                        return false;
                    }
                    if (j > 0 && ((status >> (j - 1)) & 1) == 1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public bool IsCrossRowsCompliant(int status, int upperRowStatus, int n)
        {
            for (int j = 0; j < n; j++)
            {
                if (((status >> j) & 1) == 1)
                {
                    if (j > 0 && ((upperRowStatus >> (j - 1)) & 1) == 1)
                    {
                        return false;
                    }
                    if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1) == 1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public int BitCount(int num)
        {
            uint bits = (uint)num;
            bits = bits - ((bits >> 1) & 0x55555555);
            bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
            bits = (bits + (bits >> 4)) & 0x0f0f0f0f;
            bits = (bits + (bits >> 8)) & 0x00ff00ff;
            bits = (bits + (bits >> 16)) & 0x0000ffff;
            return (int)bits;
        }

    }
}
