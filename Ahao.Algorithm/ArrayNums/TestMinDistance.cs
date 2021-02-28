using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求数组中两个元素的最小距离
    /// </summary>
    public class TestMinDistance
    {
        /// <summary>
        /// 蛮力法 
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="one"></param>
        /// <param name="two"></param>
        /// <returns></returns>
        public static int MinDistance(int[] arr, int one, int two)
        {
            if (arr == null || arr.Length < 1)
            {
                Console.WriteLine("参数不合理");
                return int.MaxValue;
            }
            int minDis = int.MaxValue;  //one和two的最小距离
            int dist = 0;
            for (int i = 0; i < arr.Length; ++i)
            {
                if (arr[i] == one)
                {
                    for (int j = 0; j < arr.Length; ++j)
                    {
                        if (arr[j] == two)
                        {
                            dist = Math.Abs(i - j); //当前遍历的one和two的距离
                            if (dist < minDis)
                                minDis = dist;
                        }
                    }
                }
            }
            return minDis;
        }


        /// <summary>
        /// 动态规划法
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="one"></param>
        /// <param name="two"></param>
        /// <returns></returns>
        public static int MinDistanceDT(int[] arr, int one, int two)
        {
            if (arr == null || arr.Length < 1)
            {
                Console.WriteLine("参数不合法");
                return int.MaxValue;
            }
            int lastPos1 = -1;      //上次遍历到one的位置
            int lastPos2 = -1;      //上次遍历到twod位置
            int minDis = int.MinValue;
            for (int i = 0; i < arr.Length; ++i)
            {
                if (arr[i] == one)
                {
                    lastPos1 = i;
                    if (lastPos2 >= 0)
                    {
                        minDis = Math.Min(minDis, lastPos1 - lastPos2);
                    }
                }
                if (arr[i] == two)
                {
                    lastPos2 = i;
                    if (lastPos1 >= 0)
                    {
                        minDis = Math.Min(minDis, lastPos2 - lastPos1);
                    }
                }
            }
            return minDis;
        }
    }
}
