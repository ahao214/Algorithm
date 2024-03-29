﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo812
{
    public class Class812
    {
        //方法一：枚举
        public double LargestTriangleArea(int[][] points)
        {
            int n = points.Length;
            double ret = 0.0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        ret = Math.Max(ret, TriangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                    }
                }
            }
            return ret;
        }

        public double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
        {
            return 0.5 * Math.Abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
        }


        //方法二：凸包

        public double LargestTriangleArea2(int[][] points)
        {
            int[][] convexHull = getConvexHull(points);
            int n = convexHull.Length;
            double ret = 0.0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1, k = i + 2; j + 1 < n; j++)
                {
                    while (k + 1 < n)
                    {
                        double curArea = TriangleArea2(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                        double nextArea = TriangleArea2(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k + 1][0], convexHull[k + 1][1]);
                        if (curArea >= nextArea)
                        {
                            break;
                        }
                        k++;
                    }
                    double area = TriangleArea2(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                    ret = Math.Max(ret, area);
                }
            }
            return ret;
        }

        public int[][] getConvexHull(int[][] points)
        {
            int n = points.Length;
            if (n < 4)
            {
                return points;
            }
            /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
            Array.Sort(points, (a, b) => {
                if (a[0] == b[0])
                {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            });
            IList<int[]> hull = new List<int[]>();
            /* 求出凸包的下半部分 */
            for (int i = 0; i < n; i++)
            {
                while (hull.Count > 1 && Cross(hull[hull.Count - 2], hull[hull.Count - 1], points[i]) <= 0)
                {
                    hull.RemoveAt(hull.Count - 1);
                }
                hull.Add(points[i]);
            }
            int m = hull.Count;
            /* 求出凸包的上半部分 */
            for (int i = n - 2; i >= 0; i--)
            {
                while (hull.Count > m && Cross(hull[hull.Count - 2], hull[hull.Count - 1], points[i]) <= 0)
                {
                    hull.RemoveAt(hull.Count - 1);
                }
                hull.Add(points[i]);
            }
            /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
            hull.RemoveAt(hull.Count - 1);
            m = hull.Count;
            int[][] hullArr = new int[m][];
            for (int i = 0; i < m; i++)
            {
                hullArr[i] = hull[i];
            }
            return hullArr;
        }

        public double TriangleArea2(int x1, int y1, int x2, int y2, int x3, int y3)
        {
            return 0.5 * Math.Abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
        }

        public int Cross(int[] p, int[] q, int[] r)
        {
            return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
        }

    }
}
