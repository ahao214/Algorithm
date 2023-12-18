using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1901
{
    public class Class1901
    {
        public int[] FindPeakGrid(int[][] mat)
        {
            int m = mat.Length, n = mat[0].Length;
            int low = 0, high = m - 1;
            while (low <= high)
            {
                int i = (low + high) / 2;
                int j = -1, maxElement = -1;
                for (int k = 0; k < n; k++)
                {
                    if (mat[i][k] > maxElement)
                    {
                        j = k;
                        maxElement = mat[i][k];
                    }
                }
                if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j])
                {
                    high = i - 1;
                    continue;
                }
                if (i + 1 < m && mat[i][j] < mat[i + 1][j])
                {
                    low = i + 1;
                    continue;
                }
                return new int[] { i, j };
            }
            return new int[0]; // impossible
        }



        public int[] FindPeakGrid2(int[][] mat)
        {
            int m = mat.Length;
            int low = 0, high = m - 1, maxIndex = 0;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                maxIndex = GetMaxIndex(mat[mid]);
                if (mat[mid][maxIndex] > mat[mid + 1][maxIndex])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            maxIndex = GetMaxIndex(mat[low]);
            return new int[] { low, maxIndex };
        }

        public int GetMaxIndex(int[] row)
        {
            int index = 0, maxNum = 0;
            int n = row.Length;
            for (int i = 0; i < n; i++)
            {
                if (row[i] > maxNum)
                {
                    maxNum = row[i];
                    index = i;
                }
            }
            return index;
        }


        int max = 0;
        int[] pos = new int[] { };

        public int[] FindPeakGrid3(int[][] mat)
        {
            for (int i = 0; i < mat.Length; i++)
            {
                for (int j = 0; j < mat[0].Length; j++)
                    Dfs(mat, i, j);
            }
            return pos;
        }

        public void Dfs(int[][] mat, int i, int j)
        {
            if (i < 0 || j < 0 || i > mat.Length - 1 || j > mat[0].Length - 1 || mat[i][j] == -1)
                return;

            if (mat[i][j] > max)
            {
                max = mat[i][j];
                pos = new int[] { i, j };
                return;
            }
            mat[i][j] = -1;
            Dfs(mat, i + 1, j);
            Dfs(mat, i - 1, j);
            Dfs(mat, i, j + 1);
            Dfs(mat, i, j - 1);
        }


        public int[] FindPeakGrid4(int[][] mat)
        {
            var m = mat.Length;
            var n = mat[0].Length;
            var result = new int[2];
            var found = false;
            while (!found)
            {
                var i = result[0];
                var j = result[1];
                if (result[0] > 0 && mat[result[0] - 1][result[1]] > mat[i][j])
                {
                    i = result[0] - 1;
                }

                if (result[0] < m - 1 && mat[result[0] + 1][result[1]] > mat[i][j])
                {
                    i = result[0] + 1;
                }

                if (result[1] > 0 && mat[result[0]][result[1] - 1] > mat[i][j])
                {
                    i = result[0];
                    j = result[1] - 1;
                }

                if (result[1] < n - 1 && mat[result[0]][result[1] + 1] > mat[i][j])
                {
                    i = result[0];
                    j = result[1] + 1;
                }

                if (i == result[0] && j == result[1]) found = true;
                result[0] = i;
                result[1] = j;
            }

            return result;
        }




    }
}
