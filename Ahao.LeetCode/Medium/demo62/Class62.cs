using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo62
{
    /*
     62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
     */
    public class Class62
    {
        public int UniquePaths(int m, int n)
        {
            if (m < n)
                return UniquePaths(n, m);
            var paths = new int[m];
            for (int i = 0; i < m; i++)
            {
                paths[i] = 1;
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    paths[j] += paths[j - 1];
                }
            }
            return paths[m - 1];
        }
    }
}
