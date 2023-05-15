using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1072
{
    public class Class1072
    {
        public int MaxEqualRowsAfterFlips(int[][] matrix)
        {
            int m = matrix.Length, n = matrix[0].Length;
            IDictionary<string, int> dictionary = new Dictionary<string, int>();
            for (int i = 0; i < m; i++)
            {
                char[] arr = new char[n];
                Array.Fill(arr, '0');
                for (int j = 0; j < n; j++)
                {
                    // 如果 matrix[i][0] 为 1，则对该行元素进行翻转
                    arr[j] = (char)('0' + (matrix[i][j] ^ matrix[i][0]));
                }
                string s = new string(arr);
                dictionary.TryAdd(s, 0);
                dictionary[s]++;
            }
            int res = 0;
            foreach (KeyValuePair<string, int> pair in dictionary)
            {
                res = Math.Max(res, pair.Value);
            }
            return res;
        }

    }
}
