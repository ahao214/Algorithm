using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1401
{
    public class Class1401
    {

        public bool CheckOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
        {
            /* 圆心在矩形内部 */
            if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2)
            {
                return true;
            }
            /* 圆心在矩形上部 */
            if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius)
            {
                return true;
            }
            /* 圆心在矩形下部 */
            if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1)
            {
                return true;
            }
            /* 圆心在矩形左部 */
            if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter && yCenter <= y2)
            {
                return true;
            }
            /* 圆心在矩形右部 */
            if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2)
            {
                return true;
            }
            /* 矩形左上角 */
            if (Distance(xCenter, yCenter, x1, y2) <= radius * radius)
            {
                return true;
            }
            /* 矩形左下角 */
            if (Distance(xCenter, yCenter, x1, y1) <= radius * radius)
            {
                return true;
            }
            /* 矩形右上角 */
            if (Distance(xCenter, yCenter, x2, y2) <= radius * radius)
            {
                return true;
            }
            /* 矩形右下角 */
            if (Distance(xCenter, yCenter, x1, y2) <= radius * radius)
            {
                return true;
            }
            /* 无交点 */
            return false;
        }

        public long Distance(int ux, int uy, int vx, int vy)
        {
            return (long)Math.Pow(ux - vx, 2) + (long)Math.Pow(uy - vy, 2);
        }




        public bool CheckOverlap2(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
        {
            double dist = 0;
            if (xCenter < x1 || xCenter > x2)
            {
                dist += Math.Min(Math.Pow(x1 - xCenter, 2), Math.Pow(x2 - xCenter, 2));
            }
            if (yCenter < y1 || yCenter > y2)
            {
                dist += Math.Min(Math.Pow(y1 - yCenter, 2), Math.Pow(y2 - yCenter, 2));
            }
            return dist <= radius * radius;
        }


    }
}
