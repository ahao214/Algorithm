using Ahao.Algorithm.Stack;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.Remoting;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 如何统计比给定整数小的数的个数
    /// </summary>
    public class TestCountOfSmallerNumber
    {
        public static List<int> CountOfSmallerNumber(int[] a, int[] queries)
        {
            var ans = new List<int>();
            for (int i = 0; i < queries.Length; i++)
            {
                //设置初始值
                ans.Add(0);
            }

            if (a.Length == 0)
            {
                return ans;
            }

            //数组排序，调用系统函数
            Array.Sort(a);
            int j = 0;
            foreach (var item in queries)
            {
                int res = MyQueue(a, item);
                ans[j++] = res;
            }
            return ans;
        }

        static int MyQueue(int[] a, int query)
        {
            int high = a.Length - 1;
            while (a[high] >= query && high > 0)
            {
                high /= 2;
            }
            while (a[high] < query && high < a.Length - 1)
            {
                high += 1;
            }
            return high;
        }

    }
}
