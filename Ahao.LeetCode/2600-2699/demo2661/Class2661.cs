using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2661
{
    public class Class2661
    {
        public int FirstCompleteIndex(int[] arr, int[][] mat)
        {
            int n = mat.Length;
            int m = mat[0].Length;
            IDictionary<int, Tuple<int, int>> dictionary = new Dictionary<int, Tuple<int, int>>();
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    dictionary.Add(mat[i][j], new Tuple<int, int>(i, j));
                }
            }
            int[] rowCnt = new int[n];
            int[] colCnt = new int[m];
            for (int i = 0; i < arr.Length; ++i)
            {
                Tuple<int, int> v = dictionary[arr[i]];
                ++rowCnt[v.Item1];
                if (rowCnt[v.Item1] == m)
                {
                    return i;
                }
                ++colCnt[v.Item2];
                if (colCnt[v.Item2] == n)
                {
                    return i;
                }
            }
            return -1;
        }




        public int FirstCompleteIndex2(int[] arr, int[][] mat)
        {            
            int m = mat.Length;
            int n = mat[0].Length;

            var map = new int[m * n + 1];
            for (int i = 0; i < m * n; i++)
            {
                map[arr[i]] = i;
            }

            var rowMin = mat.Select(row => row.Max(num => map[num]))
                            .Min();
            var colMin = Enumerable.Range(0, n)
                            .Select(j => Enumerable.Range(0, m).Max(i => map[mat[i][j]]))
                            .Min();

            return Math.Min(rowMin, colMin);
        }


    }
}
