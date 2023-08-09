using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1289
{
    public class Class1289
    {
        /// <summary>
        /// 对负数有问题
        /// </summary>
        /// <param name="grid"></param>
        /// <returns></returns>
        public int MinFallingPathSum(int[][] grid)
        {
            int sum = 0;
            int n = grid.Length;
            int minFirst = int.MaxValue;
            int minSecond = int.MaxValue;
            int minIndex = -1;
            for (int i = 0; i < n; i++)
            {
                if (grid[0][i] < minFirst)
                {
                    minFirst = grid[0][i];
                    minIndex = i;
                }
            }

            sum = minFirst;

            for (int i = 1; i < n; i++)
            {
                int[] res = GetValue(grid, i);
                if (res[0] != minIndex)
                {
                    sum += res[1];
                    minIndex = res[0];
                }
                else
                {
                    sum += res[3];
                    minIndex = res[2];
                }
            }

            return sum;
        }


        public int[] GetValue(int[][] grid, int i)
        {
            int[] res = new int[4];
            int minFirst = int.MaxValue;
            int minSecond = int.MaxValue;
            int minFirstIndex = -1;
            int minSecondIndex = -1;
            for (int j = 0; j < grid.Length; j++)
            {
                if (grid[i][j] < minFirst)
                {
                    minFirst = grid[i][j];
                    minFirstIndex = j;
                }
            }
            for (int j = 0; j < grid.Length; j++)
            {
                if (grid[i][j] < minSecond && grid[i][j] != minFirst)
                {

                    minSecond = grid[i][j];
                    minSecondIndex = j;
                }
            }

            res[0] = minFirstIndex;
            res[1] = minFirst;
            res[2] = minSecondIndex;
            res[3] = minSecond;
            return res;
        }



        public int MinFallingPathSum2(int[][] grid)
        {
            int n = grid.Length;
            int[][] d = new int[n][];
            for (int i = 0; i < n; i++)
            {
                d[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    d[i][j] = int.MaxValue;
                }
            }
            for (int i = 0; i < n; i++)
            {
                d[0][i] = grid[0][i];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (j == k)
                        {
                            continue;
                        }
                        d[i][j] = Math.Min(d[i][j], d[i - 1][k] + grid[i][j]);
                    }
                }
            }
            int res = int.MaxValue;
            for (int j = 0; j < n; j++)
            {
                res = Math.Min(res, d[n - 1][j]);
            }
            return res;
        }



        public int minFallingPathSum3(int[][] grid)
        {
            int n = grid.Length;
            int first_min_sum = 0;
            int second_min_sum = 0;
            int minIndex = -1;

            for (int i = 0; i < n; i++)
            {
                int cur_first_min_sum = int.MaxValue;
                int cur_second_min_sum = int.MaxValue;
                int cur_first_min_index = -1;

                for (int j = 0; j < n; j++)
                {
                    int cur_sum = (j != minIndex ? first_min_sum : second_min_sum) + grid[i][j];
                    if (cur_sum < cur_first_min_sum)
                    {
                        cur_second_min_sum = cur_first_min_sum;
                        cur_first_min_sum = cur_sum;
                        cur_first_min_index = j;
                    }
                    else if (cur_sum < cur_second_min_sum)
                    {
                        cur_second_min_sum = cur_sum;
                    }
                }
                first_min_sum = cur_first_min_sum;
                second_min_sum = cur_second_min_sum;
                minIndex = cur_first_min_index;
            }
            return first_min_sum;
        }



        public int MinFallingPathSum4(int[][] grid)
        {
            int n = grid.Length;
            int[] dp = new int[n];
            for (int j = 0; j < n; j++)
            {
                dp[j] = grid[0][j];
            }
            for (int i = 1; i < n; i++)
            {
                int[] dpNew = new int[n];
                for (int j = 0; j < n; j++)
                {
                    int prevMin = int.MaxValue;
                    for (int k = 0; k < n; k++)
                    {
                        if (k != j)
                        {
                            prevMin = Math.Min(prevMin, dp[k]);
                        }
                    }
                    dpNew[j] = prevMin + grid[i][j];
                }
                dp = dpNew;
            }
            int minSum = int.MaxValue;
            foreach (int sum in dp)
            {
                minSum = Math.Min(minSum, sum);
            }
            return minSum;
        }



        public int MinFallingPathSum5(int[][] grid)
        {
            int n = grid.Length;
            int[][] dp = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dp[i] = new int[n];
            }
            int first = int.MaxValue, second = int.MaxValue;
            int firstIndex = -1;
            for (int j = 0; j < n; j++)
            {
                dp[0][j] = grid[0][j];
                if (dp[0][j] < first)
                {
                    second = first;
                    first = dp[0][j];
                    firstIndex = j;
                }
                else if (dp[0][j] < second)
                {
                    second = dp[0][j];
                }
            }
            for (int i = 1; i < n; i++)
            {
                int firstNew = int.MaxValue, secondNew = int.MaxValue;
                int firstIndexNew = -1;
                for (int j = 0; j < n; j++)
                {
                    int prevMin = j != firstIndex ? first : second;
                    dp[i][j] = prevMin + grid[i][j];
                    if (dp[i][j] < firstNew)
                    {
                        secondNew = firstNew;
                        firstNew = dp[i][j];
                        firstIndexNew = j;
                    }
                    else if (dp[i][j] < secondNew)
                    {
                        secondNew = dp[i][j];
                    }
                }
                first = firstNew;
                second = secondNew;
                firstIndex = firstIndexNew;
            }
            int minSum = int.MaxValue;
            foreach (int sum in dp[n - 1])
            {
                minSum = Math.Min(minSum, sum);
            }
            return minSum;
        }



        public int MinFallingPathSum6(int[][] grid)
        {
            int n = grid.Length;
            int[] dp = new int[n];
            int first = int.MaxValue, second = int.MaxValue;
            int firstIndex = -1;
            for (int j = 0; j < n; j++)
            {
                dp[j] = grid[0][j];
                if (dp[j] < first)
                {
                    second = first;
                    first = dp[j];
                    firstIndex = j;
                }
                else if (dp[j] < second)
                {
                    second = dp[j];
                }
            }
            for (int i = 1; i < n; i++)
            {
                int firstNew = int.MaxValue, secondNew = int.MaxValue;
                int firstIndexNew = -1;
                for (int j = 0; j < n; j++)
                {
                    int prevMin = j != firstIndex ? first : second;
                    dp[j] = prevMin + grid[i][j];
                    if (dp[j] < firstNew)
                    {
                        secondNew = firstNew;
                        firstNew = dp[j];
                        firstIndexNew = j;
                    }
                    else if (dp[j] < secondNew)
                    {
                        secondNew = dp[j];
                    }
                }
                first = firstNew;
                second = secondNew;
                firstIndex = firstIndexNew;
            }
            int minSum = int.MaxValue;
            foreach (int sum in dp)
            {
                minSum = Math.Min(minSum, sum);
            }
            return minSum;
        }


        public IList<int[]> MinFallingPathSum7(int[][] grid)
        {
            int n = grid.Length;
            int[][] dp = new int[n][];
            int[][] prev = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dp[i] = new int[n];
                prev[i] = new int[n];
            }
            for (int j = 0; j < n; j++)
            {
                dp[0][j] = grid[0][j];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int prevMin = int.MaxValue;
                    for (int k = 0; k < n; k++)
                    {
                        if (k != j && dp[i - 1][k] < prevMin)
                        {
                            prevMin = dp[i - 1][k];
                            prev[i][j] = k;
                        }
                    }
                    dp[i][j] = prevMin + grid[i][j];
                }
            }
            int minSum = int.MaxValue;
            int col = -1;
            for (int j = 0; j < n; j++)
            {
                if (dp[n - 1][j] < minSum)
                {
                    minSum = dp[n - 1][j];
                    col = j;
                }
            }
            IList<int[]> path = new List<int[]>();
            int row = n - 1;
            path.Add(new int[] { row, col });
            while (row > 0)
            {
                col = prev[row][col];
                row--;
                path.Add(new int[] { row, col });
            }
            ((List<int[]>)path).Reverse();
            return path;
        }


        public IList<int[]> MinFallingPathSum8(int[][] grid)
        {
            int n = grid.Length;
            int[][] dp = new int[n][];
            int[][] prev = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dp[i] = new int[n];
                prev[i] = new int[n];
            }
            int first = int.MaxValue, second = int.MaxValue;
            int firstIndex = -1, secondIndex = -1;
            for (int j = 0; j < n; j++)
            {
                dp[0][j] = grid[0][j];
                if (dp[0][j] < first)
                {
                    second = first;
                    first = dp[0][j];
                    secondIndex = firstIndex;
                    firstIndex = j;
                }
                else if (dp[0][j] < second)
                {
                    second = dp[0][j];
                    secondIndex = j;
                }
            }
            for (int i = 1; i < n; i++)
            {
                int firstNew = int.MaxValue, secondNew = int.MaxValue;
                int firstIndexNew = -1, secondIndexNew = -1;
                for (int j = 0; j < n; j++)
                {
                    int prevMin = j != firstIndex ? first : second;
                    dp[i][j] = prevMin + grid[i][j];
                    prev[i][j] = j != firstIndex ? firstIndex : secondIndex;
                    if (dp[i][j] < firstNew)
                    {
                        secondNew = firstNew;
                        firstNew = dp[i][j];
                        secondIndexNew = firstIndexNew;
                        firstIndexNew = j;
                    }
                    else if (dp[i][j] < secondNew)
                    {
                        secondNew = dp[i][j];
                        secondIndexNew = j;
                    }
                }
                first = firstNew;
                second = secondNew;
                firstIndex = firstIndexNew;
                secondIndex = secondIndexNew;
            }
            int minSum = int.MaxValue;
            int col = -1;
            for (int j = 0; j < n; j++)
            {
                if (dp[n - 1][j] < minSum)
                {
                    minSum = dp[n - 1][j];
                    col = j;
                }
            }
            IList<int[]> path = new List<int[]>();
            int row = n - 1;
            path.Add(new int[] { row, col });
            while (row > 0)
            {
                col = prev[row][col];
                row--;
                path.Add(new int[] { row, col });
            }
            ((List<int[]>)path).Reverse();
            return path;
        }

    }
}
