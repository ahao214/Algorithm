using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo60
{
    /*
     60. 排列序列
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
     */
    public class Class60
    {
        public string GetPermutation(int n, int k)
        {
            var arr = new List<int>(n);
            for (int i = 1; i <= n; i++)
            {
                arr.Add(i);
            }

            var m = 1;
            for (int i = 1; i < n; i++)
                m *= i;
            var result = new char[n];
            k--;
            for (int i = 0, mm = n - 1; i < n; i++, mm--)
            {
                var idx = k / m;
                result[i] = (char)(arr[idx] + '0');
                arr.RemoveAt(idx);
                k %= m;
                if (mm > 0)
                    m /= mm;
            }
            return new string(result);
        }
    }
}
