using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Offer.Medium.demo17_14
{
    /*
     面试题 17.14. 最小K个数
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
     */
    public class Solution
    {
        public int[] SmallestK(int[] arr, int k)
        {
            Array.Sort(arr);
            int[] res = new int[k];
            for (int i = 0; i < k; i++)
            {
                res[i] = arr[i];
            }
            return res;
        }
    }
}
