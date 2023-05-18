using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1079
{
    public class Class1079
    {

        public int NumTilePossibilities(string tiles)
        {
            IDictionary<char, int> count = new Dictionary<char, int>();
            foreach (char t in tiles)
            {
                if (count.ContainsKey(t))
                {
                    count[t]++;
                }
                else
                {
                    count.Add(t, 1);
                }
            }
            ISet<char> tile = new HashSet<char>(count.Keys);
            return DFS(tiles.Length, count, tile) - 1;
        }

        private int DFS(int i, IDictionary<char, int> count, ISet<char> tile)
        {
            if (i == 0)
            {
                return 1;
            }
            int res = 1;
            foreach (char t in tile)
            {
                if (count[t] > 0)
                {
                    count[t]--;
                    res += DFS(i - 1, count, tile);
                    count[t]++;
                }
            }
            return res;
        }

    }
}
