using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo77
{
    /*
     77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
     */
    public class Class77
    {
        public IList<IList<int>> Combine(int n, int k)
        {
            if (n <= 0 || k < 0 || k > n)
                throw new ArgumentException();
            if (k == 0)
            {
                return new List<IList<int>>(0);
            }
            var res = new List<IList<int>>();
            var buffer = new int[k];
            Combine(1, n, buffer, 0, res);
            return res;
        }

        private void Combine(int j1, int jn, int[] buffer, int i, List<IList<int>> result)
        {
            if (i == buffer.Length)
            {
                result.Add((int[])buffer.Clone());
                return;
            }
            for (int j = j1; j <= jn; j++)
            {
                buffer[i] = j;
                Combine(j + 1, jn, buffer, i + 1, result);
            }
        }
    }
}
