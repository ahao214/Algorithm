﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo75
{
    /*
1706. 球会落何处
用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。
*/
    public class Class75
    {
        public int[] FindBall(int[][] grid)
        {
            int n = grid[0].Length;
            int[] ans = new int[n];
            Array.Fill(ans, -1);
            for (int j = 0; j < n; j++)
            {
                int col = j;
                foreach (int[] row in grid)
                {
                    int dir = row[col];
                    col += dir;
                    if (col < 0 || col == n || row[col] != dir)
                    {
                        col -= 1;
                        break;
                    }
                }
                if (col >= 0)
                {
                    ans[j] = col;
                }
            }
            return ans;
        }
    }
}
