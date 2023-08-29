﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1654
{
    public class Class1654
    {
        public int MinimumJumps(int[] forbidden, int a, int b, int x)
        {
            Queue<Tuple<int, int, int>> queue = new Queue<Tuple<int, int, int>>();
            ISet<int> visited = new HashSet<int>();
            queue.Enqueue(new Tuple<int, int, int>(0, 1, 0));
            visited.Add(0);
            int lower = 0, upper = Math.Max(forbidden.Max() + a, x) + b;
            ISet<int> forbiddenSet = new HashSet<int>();
            foreach (int position in forbidden)
            {
                forbiddenSet.Add(position);
            }
            while (queue.Count > 0)
            {
                Tuple<int, int, int> tuple = queue.Dequeue();
                int position = tuple.Item1, direction = tuple.Item2, step = tuple.Item3;
                if (position == x)
                {
                    return step;
                }
                int nextPosition = position + a;
                int nextDirection = 1;
                if (lower <= nextPosition && nextPosition <= upper && !visited.Contains(nextPosition * nextDirection) && !forbiddenSet.Contains(nextPosition))
                {
                    visited.Add(nextPosition * nextDirection);
                    queue.Enqueue(new Tuple<int, int, int>(nextPosition, nextDirection, step + 1));
                }
                if (direction == 1)
                {
                    nextPosition = position - b;
                    nextDirection = -1;
                    if (lower <= nextPosition && nextPosition <= upper && !visited.Contains(nextPosition * nextDirection) && !forbiddenSet.Contains(nextPosition))
                    {
                        visited.Add(nextPosition * nextDirection);
                        queue.Enqueue(new Tuple<int, int, int>(nextPosition, nextDirection, step + 1));
                    }
                }
            }
            return -1;
        }

    }
}
