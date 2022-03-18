using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo64
{
    /*
     64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
     */
    public class Class64
    {
        public int MinPathSum(int[][] grid)
        {
            var rows = grid.Length;
            var cols = grid[0].Length;
            var result = new int[cols];
            result[0] = grid[0][0];
            for (int col = 1; col < cols; col++)
            {
                //求第一行的每个格子的数据
                result[col] = result[col - 1] + grid[0][col];
            }
            for (int row = 1; row < rows; row++)
            {
                var line = grid[row];
                result[0] += line[0];
                for (int col = 1; col < cols; col++)
                {
                    result[col] = line[col] + Math.Min(result[col], result[col - 1]);
                }
            }
            return result[cols - 1];
        }
    }
}
