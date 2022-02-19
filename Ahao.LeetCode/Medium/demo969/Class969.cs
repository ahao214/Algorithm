using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     969. 煎饼排序
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
     */
    public class Class969
    {
        public IList<int> PancakeSort(int[] arr)
        {
            IList<int> ret = new List<int>();
            for (int n = arr.Length; n > 1; n--)
            {
                int index = 0;
                for (int i = 1; i < n; i++)
                {
                    if (arr[i] >= arr[index])
                    {
                        index = i;
                    }
                }
                if (index == n - 1)
                {
                    continue;
                }
                Reverse(arr, index);
                Reverse(arr, n - 1);
                ret.Add(index + 1);
                ret.Add(n);
            }
            return ret;
        }

        public void Reverse(int[] arr, int end)
        {
            for (int i = 0, j = end; i < j; i++, j--)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
