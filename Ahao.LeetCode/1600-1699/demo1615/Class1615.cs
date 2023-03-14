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


        /// <summary>
        /// 贪心
        /// </summary>
        /// <param name="n"></param>
        /// <param name="roads"></param>
        /// <returns></returns>
        public int MaximalNetworkRank2(int n, int[][] roads)
        {
            bool[][] connect = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                connect[i] = new bool[n];
            }
            int[] degree = new int[n];
            foreach (int[] road in roads)
            {
                int x = road[0], y = road[1];
                connect[x][y] = true;
                connect[y][x] = true;
                degree[x]++;
                degree[y]++;
            }

            int first = -1, second = -2;
            IList<int> firstArr = new List<int>();
            IList<int> secondArr = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                if (degree[i] > first)
                {
                    second = first;
                    secondArr = new List<int>(firstArr);
                    first = degree[i];
                    firstArr.Clear();
                    firstArr.Add(i);
                }
                else if (degree[i] == first)
                {
                    firstArr.Add(i);
                }
                else if (degree[i] > second)
                {
                    secondArr.Clear();
                    second = degree[i];
                    secondArr.Add(i);
                }
                else if (degree[i] == second)
                {
                    secondArr.Add(i);
                }
            }
            if (firstArr.Count == 1)
            {
                int u = firstArr[0];
                foreach (int v in secondArr)
                {
                    if (!connect[u][v])
                    {
                        return first + second;
                    }
                }
                return first + second - 1;
            }
            else
            {
                int m = roads.Length;
                if (firstArr.Count * (firstArr.Count - 1) / 2 > m)
                {
                    return first * 2;
                }
                foreach (int u in firstArr)
                {
                    foreach (int v in firstArr)
                    {
                        if (u != v && !connect[u][v])
                        {
                            return first * 2;
                        }
                    }
                }
                return first * 2 - 1;
            }
        }


        public int MaximalNetworkRank3(int n, int[][] roads)
        {
            List<List<int>> routes = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                routes.Add(new List<int>());
            }
            //双向存储两个城市之间的连接情况
            foreach (var road in roads)
            {
                routes[road[0]].Add(road[1]);
                routes[road[1]].Add(road[0]);
            }
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        //接入城市i和j的道路总数
                        int cnt = routes[i].Count + routes[j].Count;
                        //如果i和j是连通的，减去1条重复的道路
                        if (routes[i].Contains(j))
                        {
                            --cnt;
                        }
                        max = Math.Max(max, cnt);
                    }
                }
            }
            return max;
        }


    }
}
