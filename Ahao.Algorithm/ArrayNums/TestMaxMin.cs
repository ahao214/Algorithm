using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 查找数组中元素的最大值和最小值
    /// </summary>
    public class TestMaxMin
    {
        public class MaxMin
        {
            public int Max;
            public int Min;
        }

        /// <summary>
        /// 分冶法
        /// </summary>
        /// <param name="arr"></param>
        /// <returns></returns>
        public static MaxMin GetmaxAndMin(int[] arr)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
                return null;
            }

            MaxMin m = new MaxMin();
            int i = 0;
            int len = arr.Length;
            m.Max = arr[0];
            m.Min = arr[0];
            //两两分组，把较小的数放到左半部分，较大的数放到右半部分
            for (i = 0; i < len - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    int tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                }
            }
            //在各个分组的左半部分找最小值
            m.Min = arr[0];
            for (i = 2; i < len; i += 2)
            {
                if (arr[i] < m.Min)
                {
                    m.Min = arr[i];
                }
            }
            //在各个分组的右半部分找最大值
            m.Max = arr[1];
            for (i = 3; i < len; i += 2)
            {
                if (arr[i] > m.Max)
                {
                    m.Max = arr[i];
                }
            }

            //如果数组中元素个数是奇数个，最后一个元素被分为一组，需要特殊处理
            if (len % 2 == 1)
            {
                if (m.Max < arr[len - 1])
                {
                    m.Max = arr[len - 1];
                }
                if (m.Min > arr[len - 1])
                {
                    m.Min = arr[len - 1];
                }
            }
            return m;
        }





    }




}
