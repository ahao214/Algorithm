using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1615
{
    public class Class1615
    {
        /// <summary>
        /// 枚举
        /// </summary>
        /// <param name="n"></param>
        /// <param name="roads"></param>
        /// <returns></returns>
        public int MaximalNetworkRank(int n, int[][] roads)
        {
            bool[][] connect = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                connect[i] = new bool[n];
            }
            int[] degree = new int[n];
            foreach (int[] v in roads)
            {
                connect[v[0]][v[1]] = true;
                connect[v[1]][v[0]] = true;
                degree[v[0]]++;
                degree[v[1]]++;
            }

            int maxRank = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
                    maxRank = Math.Max(maxRank, rank);
                }
            }
            return maxRank;
        }

    }
}
