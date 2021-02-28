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
                    for (int j = 0; j< arr.Length; ++j)
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
    }
}
