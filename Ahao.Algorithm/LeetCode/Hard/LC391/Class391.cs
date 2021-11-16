﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Hard.LC391
{
    /// <summary>
    /// 391. 完美矩形
    /// 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
    ///如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
    /// </summary>
    public class Class391
    {
        public bool IsRectangleCover(int[][] rectangles)
        {
            long area = 0;
            int minX = rectangles[0][0], minY = rectangles[0][1], maxX = rectangles[0][2], maxY = rectangles[0][3];
            Dictionary<Point, int> cnt = new Dictionary<Point, int>();
            foreach (int[] rect in rectangles)
            {
                int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
                area += (long)(a - x) * (b - y);
                minX = Math.Min(minX, x);
                minY = Math.Min(minY, y);
                maxX = Math.Max(maxX, a);
                maxY = Math.Max(maxY, b);

                Point point1 = new Point(x, y);
                Point point2 = new Point(x, b);
                Point point3 = new Point(a, y);
                Point point4 = new Point(a, b);

                if (!cnt.ContainsKey(point1))
                {
                    cnt.Add(point1, 0);
                }
                cnt[point1]++;

                if (!cnt.ContainsKey(point2))
                {
                    cnt.Add(point2, 0);
                }
                cnt[point2]++;

                if (!cnt.ContainsKey(point3))
                {
                    cnt.Add(point3, 0);
                }
                cnt[point3]++;

                if (!cnt.ContainsKey(point4))
                {
                    cnt.Add(point4, 0);
                }
                cnt[point4]++;
            }

            Point pointMinMin = new Point(minX, minY);
            Point pointMinMax = new Point(minX, maxY);
            Point pointMaxMin = new Point(maxX, minY);
            Point pointMaxMax = new Point(maxX, maxY);
            if (area != (long)(maxX - minX) * (maxY - minY) || !cnt.ContainsKey(pointMinMin) || cnt[pointMinMin] != 1 || !cnt.ContainsKey(pointMinMax) || cnt[pointMinMax] != 1 || !cnt.ContainsKey(pointMaxMin) || cnt[pointMaxMin] != 1 || !cnt.ContainsKey(pointMaxMax) || cnt[pointMaxMax] != 1)
            {
                return false;
            }

            cnt.Remove(pointMinMin);
            cnt.Remove(pointMinMax);
            cnt.Remove(pointMaxMin);
            cnt.Remove(pointMaxMax);

            foreach (KeyValuePair<Point, int> entry in cnt)
            {
                int value = entry.Value;
                if (value != 2 && value != 4)
                {
                    return false;
                }
            }
            return true;
        }
    }

    class Point
    {
        int x;
        int y;
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override int GetHashCode()
        {
            return x + y;
        }

        public override bool Equals(object obj)
        {
            if (obj is Point)
            {
                Point point2 = (Point)obj;
                return this.x == point2.x && this.y == point2.y;
            }
            return false;
        }
    }
}
