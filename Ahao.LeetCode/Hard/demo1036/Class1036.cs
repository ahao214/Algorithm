﻿using System;
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
