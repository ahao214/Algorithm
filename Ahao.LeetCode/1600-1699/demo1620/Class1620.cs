﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1620
{
    public class Class1620
    {
        public int[] BestCoordinate(int[][] towers, int radius)
        {
            int xMax = int.MinValue, yMax = int.MinValue;
            foreach (int[] tower in towers)
            {
                int x = tower[0], y = tower[1];
                xMax = Math.Max(xMax, x);
                yMax = Math.Max(yMax, y);
            }
            int cx = 0, cy = 0;
            int maxQuality = 0;
            for (int x = 0; x <= xMax; x++)
            {
                for (int y = 0; y <= yMax; y++)
                {
                    int[] coordinate = { x, y };
                    int quality = 0;
                    foreach (int[] tower in towers)
                    {
                        int squaredDistance = GetSquaredDistance(coordinate, tower);
                        if (squaredDistance <= radius * radius)
                        {
                            double distance = Math.Sqrt(squaredDistance);
                            quality += (int)Math.Floor(tower[2] / (1 + distance));
                        }
                    }
                    if (quality > maxQuality)
                    {
                        cx = x;
                        cy = y;
                        maxQuality = quality;
                    }
                }
            }
            return new int[] { cx, cy };
        }

        public int GetSquaredDistance(int[] coordinate, int[] tower)
        {
            return (tower[0] - coordinate[0]) * (tower[0] - coordinate[0]) + (tower[1] - coordinate[1]) * (tower[1] - coordinate[1]);
        }


    }
}
