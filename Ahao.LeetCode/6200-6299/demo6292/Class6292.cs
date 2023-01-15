using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6292
{
    public class Class6292
    {
        public int[][] RangeAddQueries(int n, int[][] queries)
        {
            int[][] result = new int[n][];

            for (int i = 0; i < n; i++)
            {
                result[i] = new int[n];
            }

            int len = queries.Length;
            for (int i = 0; i < len; i++)
            {
                for (int m = queries[i][0]; m <= queries[i][2]; m++)
                {
                    for (int j = queries[i][1]; j <= queries[i][3]; j++)
                    {
                        result[m][j] += 1;
                    }
                }
            }

            return result;
        }

    }
}
