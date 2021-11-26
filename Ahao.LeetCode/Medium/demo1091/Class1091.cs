using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1091
{
    /// <summary>
    /// 1091. 二进制矩阵中的最短路径
    /// </summary>
    public class Class1091
    {
        int result = 0;
        public int ShortestPathBinaryMatrix(int[][] grid)
        {
            if (grid[0][0] == 1 || grid[grid.Length - 1][grid[0].Length - 1] == 1)
            {
                return -1;
            }

            Queue<int[]> queue = new Queue<int[]>();

            bool[,] isFinded = new bool[grid.Length, grid[0].Length];//二维布尔数组，用来防止重复遍历

            int[][] dir = new int[8][] { new int[2] { 1, 0 }, new int[2] { -1, 0 }, new int[2] { 0, 1 }, new int[2] { 0, -1 }, new int[2] { 1, 1 }, new int[2] { 1, -1 }, new int[2] { -1, 1 }, new int[2] { -1, -1 } };

            int pathLength = 1;//初始长度为1，因为路径是把起点算进去了。
            queue.Enqueue(new int[2] { 0, 0 });//让起点进队列
            int times = 1;//搜索次数，初始为1。
            isFinded[0, 0] = true;//将加入过的点的bool值设为true，防止重复遍历

            int temp = 0;//辅助函数，用来帮助记录判断这是第几次遍历。
            while (queue.Count != 0)
            {
                var v = queue.Dequeue();//将队列里的点出队，并让V引用，用来搜索周围的点。

                if (v[0] == grid.Length - 1 && v[1] == grid[0].Length - 1) return pathLength;//这个点是终点，返回。
                foreach (int[] i in dir)//搜索八个方向，将符合条件的点，然后加入到队列中。
                {
                    int x1 = v[0] + i[0];
                    int y1 = v[1] + i[1];
                    if (x1 >= 0 && x1 <= grid.Length - 1 && y1 >= 0 && y1 < grid[0].Length && grid[x1][y1] == 0 && isFinded[x1, y1] == false)
                    {
                        queue.Enqueue(new int[2] { x1, y1 });
                        isFinded[x1, y1] = true;
                    }
                }

                temp++;//每一次出队操作让Temp+1，当temp满足 == tims时，说明遍历过了一层，将结果pathlength+1.
                if (temp == times)//判断遍历过了一层的标志，temp == times，因为tims记录了上一次queue里的点的数量，当上一次的点都出队了，说明已经过了一层。
                {
                    temp = 0;
                    pathLength++;
                    times = queue.Count;
                }
            }
            return -1;//找不到终点，返回-1.
        }
    }


    public class Solution
    {
        public int ShortestPathBinaryMatrix(int[][] grid)
        {
            if (grid[0][0] == 1)
            {
                return -1;
            }
            int ans = 0, n = grid.Length;
            // 8 个方向
            int[][] directions = new int[][] { new int[] { -1, 0 }, new int[] { -1, 1 }, new int[] { 0, 1 }, new int[] { 1, 1 }, new int[] { 1, 0 }, new int[] { 1, -1 }, new int[] { 0, -1 }, new int[] { -1, -1 } };
            // Store the current index
            Queue<int[]> queue = new Queue<int[]>();
            queue.Enqueue(new int[] { 0, 0 });
            bool[,] visited = new bool[n, n];
            visited[0, 0] = true;
            while (queue.Count != 0)
            {
                ans++;
                int length = queue.Count;
                // Traverse through this layer
                for (int i = 0; i < length; ++i)
                {
                    int[] curr = queue.Dequeue();
                    if (curr[0] == n - 1 && curr[1] == n - 1) return ans;
                    foreach (int[] direction in directions)
                    {
                        int nextX = curr[0] + direction[0], nextY = curr[1] + direction[1];
                        if ((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < n) && grid[nextX][nextY] == 0 && !visited[nextX, nextY])
                        {
                            visited[nextX, nextY] = true;
                            queue.Enqueue(new int[] { nextX, nextY });
                        }
                    }
                }
            }
            return -1;
        }
    }
}
