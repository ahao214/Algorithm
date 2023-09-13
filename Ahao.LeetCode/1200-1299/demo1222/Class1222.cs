using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1222
{
    internal class Class1222
    {
        public IList<IList<int>> QueensAttacktheKing(int[][] queens, int[] king)
        {
            ISet<int> queenPos = new HashSet<int>();
            foreach (int[] queen in queens)
            {
                int x = queen[0], y = queen[1];
                queenPos.Add(x * 8 + y);
            }

            IList<IList<int>> ans = new List<IList<int>>();
            for (int dx = -1; dx <= 1; ++dx)
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    if (dx == 0 && dy == 0)
                    {
                        continue;
                    }
                    int kx = king[0] + dx, ky = king[1] + dy;
                    while (kx >= 0 && kx < 8 && ky >= 0 && ky < 8)
                    {
                        int pos = kx * 8 + ky;
                        if (queenPos.Contains(pos))
                        {
                            IList<int> posList = new List<int>();
                            posList.Add(kx);
                            posList.Add(ky);
                            ans.Add(posList);
                            break;
                        }
                        kx += dx;
                        ky += dy;
                    }
                }
            }
            return ans;
        }



        public IList<IList<int>> QueensAttacktheKing2(int[][] queens, int[] king)
        {
            IDictionary<int, int[]> candidates = new Dictionary<int, int[]>();
            int kx = king[0], ky = king[1];
            foreach (int[] queen in queens)
            {
                int qx = queen[0], qy = queen[1];
                int x = qx - kx, y = qy - ky;
                if (x == 0 || y == 0 || Math.Abs(x) == Math.Abs(y))
                {
                    int dx = Sgn(x), dy = Sgn(y);
                    int key = dx * 10 + dy;
                    if (!candidates.ContainsKey(key))
                    {
                        candidates.Add(key, new int[] { queen[0], queen[1], Math.Abs(x) + Math.Abs(y) });
                    }
                    else if (candidates[key][2] > Math.Abs(x) + Math.Abs(y))
                    {
                        candidates[key] = new int[] { queen[0], queen[1], Math.Abs(x) + Math.Abs(y) };
                    }
                }
            }

            IList<IList<int>> ans = new List<IList<int>>();
            foreach (KeyValuePair<int, int[]> pair in candidates)
            {
                int[] value = pair.Value;
                IList<int> posList = new List<int>();
                posList.Add(value[0]);
                posList.Add(value[1]);
                ans.Add(posList);
            }
            return ans;
        }

        public int Sgn(int x)
        {
            return x > 0 ? 1 : (x == 0 ? 0 : -1);
        }


    }
}
