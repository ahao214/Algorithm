using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

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


        //返回值列表中有两个元素，第一个值为子数组的最小值，第二个元素为最大值
        public List<int> GetMaxAndMin(int[] arr, int l, int r)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
                return null;
            }
            List<int> list = new List<int>();
            int m = (l + r) / 2;    //求中点
            int max;
            int min;
            if (l == r)    //l和r之间只有一个元素
            {
                list.Add(arr[l]);
                list.Add(arr[r]);
                return list;
            }

            if (l + 1 == r)  //l和r之间只有两个元素
            {
                if (arr[l] >= arr[r])
                {
                    max = arr[l];
                    min = arr[r];
                }
                else
                {
                    max = arr[r];
                    min = arr[l];
                }
                list.Add(min);
                list.Add(max);
                return list;
            }

            //递归计算左半部分
            List<int> lList = GetMaxAndMin(arr, l, m);
            //递归计算右半部分
            List<int> rList = GetMaxAndMin(arr, m + 1, r);
            //总的最大值
            max = (lList[1] > rList[1]) ? lList[1] : rList[1];
            //总的最小值
            min = (lList[0] < rList[0]) ? lList[0] : rList[0];
            list.Add(min);
            list.Add(max);
            return list;
        }
    }
}
