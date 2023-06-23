using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1659
{
    public class Class1659
    {

        const int T = 243, N = 5, M = 6;
        int n, m, tot;
        int[][] maskBits;
        int[] ivCount;
        int[] evCount;
        int[] innerScore;
        int[][] interScore;
        int[][][][] d;
        // 邻居间的分数
        static int[][] score = {
        new int[]{0, 0, 0},
        new int[]{0, -60, -10},
        new int[]{0, -10, 40} };



        public int GetMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
        {
            this.n = n;
            this.m = m;
            // 状态总数为 3^n
            this.tot = (int)Math.Pow(3, n);
            this.maskBits = new int[T][];
            for (int i = 0; i < T; i++)
            {
                this.maskBits[i] = new int[N];
            }
            this.ivCount = new int[T];
            this.evCount = new int[T];
            this.innerScore = new int[T];
            this.interScore = new int[T][];
            for (int i = 0; i < T; i++)
            {
                this.interScore[i] = new int[T];
            }
            this.d = new int[N][][][];

            InitData();
            // 记忆化搜索数组，初始化为 -1，表示未赋值
            for (int i = 0; i < N; i++)
            {
                d[i] = new int[T][][];
                for (int j = 0; j < T; j++)
                {
                    d[i][j] = new int[M + 1][];
                    for (int k = 0; k <= M; k++)
                    {
                        d[i][j][k] = new int[M + 1];
                        Array.Fill(d[i][j][k], -1);
                    }
                }
            }
            return DFS(0, 0, introvertsCount, extrovertsCount);
        }

        public void InitData()
        {
            // 计算行内分数
            for (int mask = 0; mask < tot; mask++)
            {
                int maskTmp = mask;
                for (int i = 0; i < n; i++)
                {
                    int x = maskTmp % 3;
                    maskBits[mask][i] = x;
                    maskTmp /= 3;
                    if (x == 1)
                    {
                        ivCount[mask]++;
                        innerScore[mask] += 120;
                    }
                    else if (x == 2)
                    {
                        evCount[mask]++;
                        innerScore[mask] += 40;
                    }
                    if (i > 0)
                    {
                        innerScore[mask] += score[x][maskBits[mask][i - 1]];
                    }
                }
            }
            // 计算行间分数
            for (int i = 0; i < tot; i++)
            {
                for (int j = 0; j < tot; j++)
                {
                    interScore[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        interScore[i][j] += score[maskBits[i][k]][maskBits[j][k]];
                    }
                }
            }
        }

        public int DFS(int row, int premask, int iv, int ev)
        {
            if (row == m || (iv == 0 && ev == 0))
            {
                return 0;
            }
            // 如果该状态已经计算过答案，则直接返回
            if (d[row][premask][iv][ev] != -1)
            {
                return d[row][premask][iv][ev];
            }
            // 合法状态，初始值为 0
            int res = 0;
            for (int mask = 0; mask < tot; mask++)
            {
                // mask 包含的内向人数不能超过 iv ，外向人数不能超过 ev
                if (ivCount[mask] > iv || evCount[mask] > ev)
                {
                    continue;
                }
                res = Math.Max(res, DFS(row + 1, mask, iv - ivCount[mask], ev - evCount[mask])
                                + innerScore[mask]
                                + interScore[premask][mask]);
            }
            d[row][premask][iv][ev] = res;
            return res;
        }





        int[] p;



        public int GetMaxGridHappiness1(int m, int n, int introvertsCount, int extrovertsCount)
        {
            this.n = n;
            this.m = m;
            // 状态总数为 3^n
            this.tot = (int)Math.Pow(3, n);
            this.p = new int[N];
            p[0] = 1;
            for (int i = 1; i < n; i++)
            {
                p[i] = p[i - 1] * 3;
            }
            this.d = new int[N * N][][][];

            // 记忆化搜索数组，初始化为 -1，表示未赋值
            for (int i = 0; i < N * N; i++)
            {
                d[i] = new int[T][][];
                for (int j = 0; j < T; j++)
                {
                    d[i][j] = new int[M + 1][];
                    for (int k = 0; k <= M; k++)
                    {
                        d[i][j][k] = new int[M + 1];
                        Array.Fill(d[i][j][k], -1);
                    }
                }
            }
            return DFS1(0, 0, introvertsCount, extrovertsCount);
        }

        public int DFS1(int pos, int mask, int iv, int ev)
        {
            if (pos == n * m || (iv == 0 && ev == 0))
            {
                return 0;
            }
            int res = d[pos][mask][iv][ev];
            if (res != -1)
            {
                return res;
            }
            res = 0;
            int up = mask / p[n - 1], left = mask % 3;
            // 若处于第一列，则左侧没有元素，将 left 置为 0
            if (pos % n == 0)
            {
                left = 0;
            }
            for (int i = 0; i < 3; i++)
            {
                if ((i == 1 && iv == 0) || (i == 2 && ev == 0))
                {
                    continue;
                }
                int nextMask = mask % p[n - 1] * 3 + i;
                int scoreSum = DFS(pos + 1, nextMask, iv - (i == 1 ? 1 : 0), ev - (i == 2 ? 1 : 0))
                                + score[up][i]
                                + score[left][i];
                if (i == 1)
                {
                    scoreSum += 120;
                }
                else if (i == 2)
                {
                    scoreSum += 40;
                }
                res = Math.Max(res, scoreSum);
            }
            d[pos][mask][iv][ev] = res;
            return res;
        }


    }
}
