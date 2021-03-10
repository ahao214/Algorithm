using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解迷宫问题
    /// </summary>
    public class TestMaze
    {
        public int N = 4;

        //打印从起点到终点的路线
        public void PrintSolution(int[][] sol)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    Console.Write(sol[i][j] + " ");
                }
                Console.WriteLine();
            }
        }


        //判断x和y是否是一个合理的单元
        bool IsSafe(int[][] maze, int x, int y)
        {
            return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
        }

        /// <summary>
        /// 使用回溯的方法找到一条从左上角到右下角的路径        
        /// </summary>
        /// <param name="maze">表示迷宫</param>
        /// <param name="x">起点</param>
        /// <param name="y">起点</param>
        /// <param name="sol">存储结果</param>
        /// <returns></returns>
        public bool GetPath(int[][] maze, int x, int y, int[][] sol)
        {
            //到达目的地
            if (x == N - 1 && y == N - 1)
            {
                sol[x][y] = 1;
                return true;
            }
            //判断maze[x][y]是否是一个可走的单元
            if (IsSafe(maze, x, y) == true)
            {
                //标记当前单元为1
                sol[x][y] = 1;

                //向右走一步
                if (GetPath(maze, x + 1, y, sol))
                    return true;

                //向下走一步
                if (GetPath(maze, x, y + 1, sol))
                    return true;

                //标记当前单元为0用来表示这条路不可行，然后回溯
                sol[x][y] = 0;
                return false;
            }
            return false;

        }
    }
}
