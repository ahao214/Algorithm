using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1000
{
    public class Class1000
    {

        const int INF = 0x3f3f3f3f;
        int[][][] d;
        int[] sum;
        int k;

        public int MergeStones(int[] stones, int k)
        {
            int n = stones.Length;
            if ((n - 1) % (k - 1) != 0)
            {
                return -1;
            }
            this.k = k;
            d = new int[n][][];
            for (int i = 0; i < n; i++)
            {
                d[i] = new int[n][];
                for (int j = 0; j < n; j++)
                {
                    d[i][j] = new int[k + 1];
                    Array.Fill(d[i][j], -1);
                }
            }
            sum = new int[n];

            // 初始化
            for (int i = 0, s = 0; i < n; i++)
            {
                d[i][i][1] = 0;
                s += stones[i];
                sum[i] = s;
            }
            int res = Get(0, n - 1, 1);
            return res;
        }

        public int Get(int l, int r, int t)
        {
            // 若 d[l][r][t] 不为 -1，表示已经在之前的递归被求解过，直接返回答案
            if (d[l][r][t] != -1)
            {
                return d[l][r][t];
            }
            // 当石头堆数小于 t 时，一定无解
            if (t > r - l + 1)
            {
                return INF;
            }
            if (t == 1)
            {
                int res = Get(l, r, k);
                if (res == INF)
                {
                    return d[l][r][t] = INF;
                }
                return d[l][r][t] = res + (sum[r] - (l == 0 ? 0 : sum[l - 1]));
            }
            int val = INF;
            for (int p = l; p < r; p += (k - 1))
            {
                val = Math.Min(val, Get(l, p, 1) + Get(p + 1, r, t - 1));
            }
            return d[l][r][t] = val;
        }



        
        public int MergeStones2(int[] stones, int k)
        {
            int n = stones.Length;
            if ((n - 1) % (k - 1) != 0)
            {
                return -1;
            }

            int[][][] d = new int[n][][];
            int[] sum = new int[n];

            for (int i = 0; i < n; i++)
            {
                d[i] = new int[n][];
                for (int j = 0; j < n; j++)
                {
                    d[i][j] = new int[k + 1];
                    Array.Fill(d[i][j], INF);
                }
            }

            for (int i = 0, s = 0; i < n; i++)
            {
                d[i][i][1] = 0;
                s += stones[i];
                sum[i] = s;
            }

            for (int len = 2; len <= n; len++)
            {
                for (int l = 0; l < n && l + len - 1 < n; l++)
                {
                    int r = l + len - 1;
                    for (int t = 2; t <= k; t++)
                    {
                        for (int p = l; p < r; p += k - 1)
                        {
                            d[l][r][t] = Math.Min(d[l][r][t], d[l][p][1] + d[p + 1][r][t - 1]);
                        }
                    }
                    d[l][r][1] = Math.Min(d[l][r][1], d[l][r][k] + sum[r] - (l == 0 ? 0 : sum[l - 1]));
                }
            }
            return d[0][n - 1][1];
        }


    }
}
