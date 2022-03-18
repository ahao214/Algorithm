using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo63
{
    /*
     63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。
     */
    public class Class63
    {
        public int UniquePathsWithObstacles(int[][] obstacleGrid)
        {
            var n = obstacleGrid.Length;
            var m = obstacleGrid[0].Length;
            var paths = new int[m];
            for (int i = 0; i < m; i++)
            {
                paths[i] = (i > 0 && paths[i - 1] == 0) || obstacleGrid[0][i] != 0 ? 0 : 1;
            }
            for (int i = 1; i < n; i++)
            {
                var line = obstacleGrid[i];
                if (line[0] != 0)
                    paths[0] = 0;
                for (int j = 1; j < m; j++)
                {
                    if (line[j] != 0)
                    {
                        paths[j] = 0;
                    }
                    else
                    {
                        paths[j] += paths[j - 1];
                    }
                }
            }
            return paths[m - 1];
        }
    }
}
