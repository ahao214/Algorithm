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
        public static int MinDistance(int[] a, int[] b, int[] c)
        {
            int aLen = a.Length;
            int bLen = b.Length;
            int cLen = c.Length;

            int minDist = Max(Math.Abs(a[0] - b[0]), Math.Abs(a[0] - c[0]), Math.Abs(b[0] - c[0]));
            int dist = 0;
            for (int i = 0; i < aLen; i++)
            {
                for (int j = 0; j < bLen; j++)
                {
                    for (int k = 0; k < cLen; k++)
                    {
                        //求距离
                        dist = Max(Math.Abs(a[i] - b[j]), Math.Abs(a[i] - c[k]), Math.Abs(b[j] - c[k]));
                        //找出最小值
                        if (minDist > dist)
                        {
                            minDist = dist;
                        }
                    }
                }
            }
            return minDist;
        }

        /// <summary>
        /// 最小距离法
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        public static int MinDistanceLow(int[] a, int[] b, int[] c)
        {
            int aLen = a.Length;
            int bLen = b.Length;
            int cLen = c.Length;
            int curDist = 0;
            int min = 0;
            int minDist = int.MaxValue;
            int i = 0;  //数组a的下标
            int j = 0;  //数组b的下标
            int k = 0;  //数组c的下标
            while (true)
            {
                curDist = Max(Math.Abs(a[i] - b[j]), Math.Abs(a[i] - c[k]), Math.Abs(b[j] - c[k]));
                if (curDist < minDist)
                {
                    minDist = curDist;
                }
                //找出当前遍历到三个数组中的最小值
                min = Min(a[i], b[j], c[k]);
                if (min == a[i])
                {
                    if (++i >= aLen)
                        break;
                }
                else if (min == b[j])
                {
                    if (++j >= bLen)
                        break;
                }
                else
                {
                    if (++k >= cLen)
                        break;
                }
            }
            return minDist;
        }

        /// <summary>
        /// 数学运算法
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        public static int MinDistanceA(int[] a, int[] b, int[] c)
        {
            int aLen = a.Length;
            int bLen = b.Length;
            int cLen = c.Length;
            int MinSum = 0; //最小的绝对值和
            int Sum = 0;    //计算三个绝对值的和，与最小值做比较
            int MinOFabc = 0;   //a[i],b[j],c[k]的最小值
            int cnt = 0;    //循环次数统计，最多是1+m+n次
            int i = 0, j = 0, k = 0;    //a,b,c 三个数组的下标索引
            MinSum = (Math.Abs(a[i] - b[j]) + Math.Abs(a[i] - c[k]) + Math.Abs(b[j] - c[k])) / 2;
            for (cnt = 0; cnt <= aLen + aLen + cLen; cnt++)
            {
                Sum = (Math.Abs(a[i] - b[j]) + Math.Abs(a[i] - c[k]) + Math.Abs(b[j] - c[k])) / 2;
                MinSum = MinSum < Sum ? MinSum : Sum;
                MinOFabc = Min(a[i], b[j], c[k]);   //找到a[i] b[j] c[k]的最小值
                //判断哪个是最小值，做相应的索引移动
                if (MinOFabc == a[i])
                {
                    if (++i >= aLen)
                        break;
                }   //a[i]最小，移动i
                if (MinOFabc == b[j])
                {
                    if (++j >= bLen)
                        break;
                }   //b[j]最小，移动j
                if (MinOFabc == c[k])
                {
                    if (++k >= cLen)
                        break;
                }   //c[k]最小，移动k
            }
            return MinSum;
        }


    }
}
