using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1036
{
    /// <summary>
    /// 1036. 逃离大迷宫
    /// </summary>
    public class Class1036
    {
        //方法一：有限步数的广度优先搜索
        // 在包围圈中
        const int BLOCKED = -1;
        // 不在包围圈中
        const int VALID = 0;
        // 无论在不在包围圈中，但在 n(n-1)/2 步搜索的过程中经过了 target
        const int FOUND = 1;

        int[][] dirs = { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };
        const int BOUNDARY = 1000000;

        public bool IsEscapePossible(int[][] blocked, int[] source, int[] target)
        {
            if (blocked.Length < 2)
            {
                return true;
            }

            ISet<Pair> hashBlocked = new HashSet<Pair>();
            foreach (int[] pos in blocked)
            {
                hashBlocked.Add(new Pair(pos[0], pos[1]));
            }

            int result = Check(blocked, source, target, hashBlocked);
            if (result == FOUND)
            {
                return true;
            }
            else if (result == BLOCKED)
            {
                return false;
            }
            else
            {
                result = Check(blocked, target, source, hashBlocked);
                return result != BLOCKED;
            }
        }

        public int Check(int[][] blocked, int[] start, int[] finish, ISet<Pair> hashBlocked)
        {
            int sx = start[0], sy = start[1];
            int fx = finish[0], fy = finish[1];
            int countdown = blocked.Length * (blocked.Length - 1) / 2;
            Pair startPair = new Pair(sx, sy);
            Queue<Pair> queue = new Queue<Pair>();
            queue.Enqueue(startPair);
            ISet<Pair> visited = new HashSet<Pair>();
            visited.Add(startPair);
            while (queue.Count > 0 && countdown > 0)
            {
                Pair pair = queue.Dequeue();
                int x = pair.X, y = pair.Y;
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    Pair newPair = new Pair(nx, ny);
                    if (nx >= 0 && nx < BOUNDARY && ny >= 0 && ny < BOUNDARY && !hashBlocked.Contains(newPair) && !visited.Contains(newPair))
                    {
                        if (nx == fx && ny == fy)
                        {
                            return FOUND;
                        }
                        --countdown;
                        queue.Enqueue(newPair);
                        visited.Add(newPair);
                    }
                }
            }
            if (countdown > 0)
            {
                return BLOCKED;
            }
            return VALID;
        }



        //方法二：离散化 + 广度优先搜索
        const int BOUNDARY2 = 1000000;
        int[][] dirs2 = { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };

        public bool IsEscapePossible2(int[][] blocked, int[] source, int[] target)
        {
            if (blocked.Length < 2)
            {
                return true;
            }
            ISet<int> rowsSet = new HashSet<int>();
            ISet<int> columnsSet = new HashSet<int>();
            List<int> rows = new List<int>();
            List<int> columns = new List<int>();
            // 离散化
            foreach (int[] pos in blocked)
            {
                if (rowsSet.Add(pos[0]))
                {
                    rows.Add(pos[0]);
                }
                if (columnsSet.Add(pos[1]))
                {
                    columns.Add(pos[1]);
                }
            }
            if (rowsSet.Add(source[0]))
            {
                rows.Add(source[0]);
            }
            if (rowsSet.Add(target[0]))
            {
                rows.Add(target[0]);
            }
            if (columnsSet.Add(source[1]))
            {
                columns.Add(source[1]);
            }
            if (columnsSet.Add(target[1]))
            {
                columns.Add(target[1]);
            }
            rows.Sort();
            columns.Sort();

            Dictionary<int, int> rDictionary = new Dictionary<int, int>();
            Dictionary<int, int> cDictionary = new Dictionary<int, int>();

            int rId = (rows[0] == 0 ? 0 : 1);
            rDictionary.Add(rows[0], rId);
            for (int i = 1; i < rows.Count; ++i)
            {
                rId += (rows[i] == rows[i - 1] + 1 ? 1 : 2);
                rDictionary.Add(rows[i], rId);
            }
            if (rows[rows.Count - 1] != BOUNDARY2 - 1)
            {
                ++rId;
            }

            int cId = (columns[0] == 0 ? 0 : 1);
            cDictionary.Add(columns[0], cId);
            for (int i = 1; i < columns.Count; ++i)
            {
                cId += (columns[i] == columns[i - 1] + 1 ? 1 : 2);
                cDictionary.Add(columns[i], cId);
            }
            if (columns[columns.Count - 1] != BOUNDARY2 - 1)
            {
                ++cId;
            }

            int[][] grid = new int[rId + 1][];
            for (int i = 0; i <= rId; ++i)
            {
                grid[i] = new int[cId + 1];
            }
            foreach (int[] pos in blocked)
            {
                int x = pos[0], y = pos[1];
                grid[rDictionary[x]][cDictionary[y]] = 1;
            }

            int sx = rDictionary[source[0]], sy = cDictionary[source[1]];
            int tx = rDictionary[target[0]], ty = cDictionary[target[1]];

            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            queue.Enqueue(new Tuple<int, int>(sx, sy));
            grid[sx][sy] = 1;
            while (queue.Count > 0)
            {
                Tuple<int, int> tuple = queue.Dequeue();
                int x = tuple.Item1, y = tuple.Item2;
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dirs2[d][0], ny = y + dirs2[d][1];
                    if (nx >= 0 && nx <= rId && ny >= 0 && ny <= cId && grid[nx][ny] != 1)
                    {
                        if (nx == tx && ny == ty)
                        {
                            return true;
                        }
                        queue.Enqueue(new Tuple<int, int>(nx, ny));
                        grid[nx][ny] = 1;
                    }
                }
            }
            return false;
        }


        const int BDY = 1000000;
        readonly int[] dir4 = { 0, 1, 0, -1, 1, 0, -1, 0 };
        public bool IsEscapePossible3(int[][] blocked, int[] source, int[] target)//1036. 逃离大迷宫,离散以合并空格
        {
            List<int[]> blo = new List<int[]>(blocked) { source, target };//全部关键点
            int n = blo.Count, k = blocked.Length, i, last;
            if (k < 2) return true;
            Dictionary<int, int> dr = new Dictionary<int, int>(), dc = new Dictionary<int, int>();//离散坐标对应字典

            blo.Sort((a, b) => a[0] - b[0]);//行标排序
            for (i = 0, last = -1; i < n; i++)
            {
                switch (blo[i][0] - last)
                {
                    case 0: continue;//相同
                    case 1: break;//相邻
                    default: dr[last + 1] = dr.Count; break;//相隔
                }
                dr[blo[i][0]] = dr.Count; last = blo[i][0];
            }
            if (last < BDY - 1) dr[last + 1] = dr.Count;//最后是否可加空行
            blo.Sort((a, b) => a[1] - b[1]);//列标排序
            for (i = 0, last = -1; i < n; i++)
            {
                switch (blo[i][1] - last)
                {
                    case 0: continue;//相同
                    case 1: break;//相邻
                    default: dc[last + 1] = dc.Count; break;//相隔
                }
                dc[blo[i][1]] = dc.Count; last = blo[i][1];
            }
            if (last < BDY - 1) dc[last + 1] = dc.Count;//最后是否可加空列
            int r = dr.Count, c = dc.Count;
            int[,] grid = new int[r, c];//准备保存离散化地图
            foreach (int[] pos in blocked)//构建离散化地图（空地将只保留一格）
            {
                int xx = dr[pos[0]], yy = dc[pos[1]]; grid[xx, yy] = 1;
            }//设为障碍
            int sx = dr[source[0]], sy = dc[source[1]], tx = dr[target[0]], ty = dc[target[1]];//起点、终点
            Queue<Tuple<int, int>> open = new Queue<Tuple<int, int>>();//二元组队列
            open.Enqueue(new Tuple<int, int>(sx, sy));
            grid[sx, sy] = 1;//状态设为障碍
            while (open.Count > 0)//在离散地图上进行广度优先搜索
            {
                Tuple<int, int> tuple = open.Dequeue();
                int x = tuple.Item1, y = tuple.Item2;
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dir4[d << 1], ny = y + dir4[d << 1 | 1];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx, ny] < 1)
                    {
                        if (nx == tx && ny == ty) return true;//可达
                        open.Enqueue(new Tuple<int, int>(nx, ny));
                        grid[nx, ny] = 1;//状态设为障碍
                    }
                }
            }
            return false;//不可达
        }
    }


    public class Pair
    {
        public int X
        {
            get; set;
        }
        public int Y
        {
            get; set;
        }

        public Pair(int x, int y)
        {
            this.X = x;
            this.Y = y;
        }

        public override int GetHashCode()
        {
            return (int)(((long)X) << 20 | Y);
        }

        public override bool Equals(object obj)
        {
            Pair pair2 = obj as Pair;
            if (pair2 == null)
            {
                return false;
            }
            return X == pair2.X && Y == pair2.Y;
        }
    }
}
