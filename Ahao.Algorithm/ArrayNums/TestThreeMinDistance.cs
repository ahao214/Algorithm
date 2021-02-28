using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解最小三元组距离
    /// </summary>
    public class TestThreeMinDistance
    {
        public static int Max(int a, int b, int c)
        {
            int max = a < b ? b : a;
            max = max < c ? c : max;
            return max;
        }

        public static int Min(int a, int b, int c)
        {
            int min = a < b ? a : b;
            min = min < c ? min : c;
            return min;
        }


        /// <summary>
        /// 蛮力法
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        public static int MinDistance(int [] a ,int [] b ,int [] c)
        {
            int aLen = a.Length;
            int bLen = b.Length;
            int cLen = c.Length;

            int minDist = Max(Math.Abs(a[0] - b[0]), Math.Abs(a[0] - c[0]), Math.Abs(b[0] - c[0]));
            int dist = 0;
            for(int i=0;i<aLen;i++)
            {
                for (int j=0;j<bLen;j++)
                {
                    for (int k=0;k<cLen;k++)
                    {
                        //求距离
                        dist = Max(Math.Abs(a[i] - b[j]), Math.Abs(a[i] - c[k]), Math.Abs(b[j] - c[k]));
                        //找出最小值
                        if(minDist >dist )
                        {
                            minDist = dist;
                        }
                    }
                }
            }
            return minDist;
        }
    }
}
