using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解数组排序前后最大的间隔
    /// </summary>
    public class TestMaxGap
    {
        struct Bucket
        {
            public int Min { get; set; }
            public int Max { get; set; }
        }

        public static int MaxGap(int[] a)
        {
            int n = a.Length;
            int max = 0, min = 0, i;
            double bucketLen;
            //扫描一遍数组，得到最大值max和最小值min，复杂度为O(n)
            for (i = 0; i < n; i++)
            {
                if (a[i] > max)
                    max = a[i];
                if (a[i] < min)
                    min = a[i];
            }

            bucketLen = (max - min) * 1.0 / (n - 1);  //桶的大小，即每段区域的大小
            Bucket[] bucket = new Bucket[n - 1];    //开辟n-1段区域

            //初始化每段区域的最大和最小值，即初始化每段区域为空
            for (i = 0; i < n - 1; i++)
            {
                bucket[i].Max = int.MinValue;
                bucket[i].Min = int.MaxValue;
            }
            //初始化第一个区域的最大、最小值为min
            //初始化第n-1个区域的最大、最小值为max
            bucket[0].Max = min;
            bucket[0].Min = min;
            bucket[n - 2].Max = max;
            bucket[n - 2].Min = max;
            //将数组中的其他n-2个数，放到n-1个区域中。并且获得每个区域的最大、最小值。复杂度为O(n)
            for (i = 0; i < n; i++)
            {
                int index;
                if (a[i] != min && a[i] != max)
                {
                    index = (int)((a[i] - min) * 1.0 / bucketLen);
                    //获取当前元素坐在区域的区域号。区域号从0~n-2
                    if (bucket[index].Max < a[i])
                        bucket[index].Max = a[i];
                    if (bucket[index].Min > a[i])
                        bucket[index].Min = a[i];
                }
            }

            int low = -1, high = -1, maxGap = 0, curGap, pre = 0;
            for (i = 1; i < n - 1; ++i)
            {
                if (bucket[i].Max != int.MinValue)//区域i非空
                {
                    curGap = bucket[i].Min - bucket[pre].Max;
                    if (curGap > maxGap)
                    {
                        maxGap = curGap;
                        low = bucket[pre].Max;
                        high = bucket[i].Min;
                    }
                    pre = i;
                }
            }
            return maxGap;
        }

    }
}
