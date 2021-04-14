using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 求解最多有多少个点在一条直线上的问题
    /// </summary>
    public class TestMaxPoints
    {       
        public static int MaxPoints(Point[] points)
        {
            if (points == null || points.Length == 0)
                return 0;
            if (points.Length <= 2)
                return points.Length;

            int result = 0;
            for (int i = 0; i < points.Length; i++)
            {
                int pointx = points[i].x;
                int pointy = points[i].y;
                Dictionary<Double, int> map = new Dictionary<double, int>();
                int samep = 0;
                int samex = 0;
                for (int j = 0; j < points.Length; j++)
                {
                    if (j != i)
                    {
                        if (points[j].x == points[i].x && points[j].y == points[i].y)
                            samep++;
                        if (points[j].x == points[i].x)
                        {
                            samex++;
                            continue;
                        }
                        double k = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                        if (map.ContainsKey(k))
                        {
                            map[k] = map[k] + 1;
                        }
                        else
                        {
                            map.Add(k, 2);
                        }
                        result = Math.Max(result, map[k] + samep);
                    }
                }
                result = Math.Max(result, samex);
            }
            return result;
        }
    }
    public class Point
    {
        public int x;
        public int y;
        public Point()
        {
            x = 0;
            y = 0;
        }
        public Point(int a, int b)
        {
            x = a;
            y = b;
        }
    }

}
