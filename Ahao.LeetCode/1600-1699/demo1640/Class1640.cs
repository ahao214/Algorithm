using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1640
{
    public class Class1640
    {
        //哈希表
        public bool CanFormArray(int[] arr, int[][] pieces)
        {
            int n = arr.Length, m = pieces.Length;
            Dictionary<int, int> index = new Dictionary<int, int>();
            for (int i = 0; i < m; i++)
            {
                index.Add(pieces[i][0], i);
            }
            for (int i = 0; i < n;)
            {
                if (!index.ContainsKey(arr[i]))
                {
                    return false;
                }
                int j = index[arr[i]], len = pieces[j].Length;
                for (int k = 0; k < len; k++)
                {
                    if (arr[i + k] != pieces[j][k])
                    {
                        return false;
                    }
                }
                i = i + len;
            }
            return true;
        }
    }
}
