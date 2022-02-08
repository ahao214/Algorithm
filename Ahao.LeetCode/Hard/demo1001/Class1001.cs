using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1001
{
    /*
     1001. 网格照明
在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。
     */
    public class Class1001
    {       
        public int[] GridIllumination(int n, int[][] lamps, int[][] queries)
        {
            Dictionary<int, int> row = new Dictionary<int, int>();
            Dictionary<int, int> col = new Dictionary<int, int>();
            Dictionary<int, int> diagonal = new Dictionary<int, int>();
            Dictionary<int, int> antiDiagonal = new Dictionary<int, int>();
            ISet<long> points = new HashSet<long>();
            foreach (int[] lamp in lamps)
            {
                if (!points.Add(Hash(lamp[0], lamp[1])))
                {
                    continue;
                }
                if (!row.ContainsKey(lamp[0]))
                {
                    row.Add(lamp[0], 0);
                }
                row[lamp[0]]++;
                if (!col.ContainsKey(lamp[1]))
                {
                    col.Add(lamp[1], 0);
                }
                col[lamp[1]]++;
                if (!diagonal.ContainsKey(lamp[0] - lamp[1]))
                {
                    diagonal.Add(lamp[0] - lamp[1], 0);
                }
                diagonal[lamp[0] - lamp[1]]++;
                if (!antiDiagonal.ContainsKey(lamp[0] + lamp[1]))
                {
                    antiDiagonal.Add(lamp[0] + lamp[1], 0);
                }
                antiDiagonal[lamp[0] + lamp[1]]++;
            }
            int[] ret = new int[queries.Length];
            for (int i = 0; i < queries.Length; i++)
            {
                int r = queries[i][0], c = queries[i][1];
                if (row.ContainsKey(r) && row[r] > 0)
                {
                    ret[i] = 1;
                }
                else if (col.ContainsKey(c) && col[c] > 0)
                {
                    ret[i] = 1;
                }
                else if (diagonal.ContainsKey(r - c) && diagonal[r - c] > 0)
                {
                    ret[i] = 1;
                }
                else if (antiDiagonal.ContainsKey(r + c) && antiDiagonal[r + c] > 0)
                {
                    ret[i] = 1;
                }
                for (int x = r - 1; x <= r + 1; x++)
                {
                    for (int y = c - 1; y <= c + 1; y++)
                    {
                        if (x < 0 || y < 0 || x >= n || y >= n)
                        {
                            continue;
                        }
                        if (points.Remove(Hash(x, y)))
                        {
                            row[x]--;
                            if (row[x] == 0)
                            {
                                row.Remove(x);
                            }
                            col[y]--;
                            if (col[y] == 0)
                            {
                                col.Remove(y);
                            }
                            diagonal[x - y]--;
                            if (diagonal[x - y] == 0)
                            {
                                diagonal.Remove(x - y);
                            }
                            antiDiagonal[x + y]--;
                            if (antiDiagonal[x + y] == 0)
                            {
                                antiDiagonal.Remove(x + y);
                            }
                        }
                    }
                }
            }
            return ret;
        }

        public long Hash(int x, int y)
        {
            return (long)x + ((long)y << 32);
        }
    }
}

