using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1331
{
    public class Class1331
    {

        public int[] ArrayRankTransform(int[] arr)
        {
            int len = arr.Length;
            int[] sortedArr = new int[len];
            Array.Copy(arr, 0, sortedArr, 0, len);
            Array.Sort(sortedArr);
            Dictionary<int, int> ranks = new Dictionary<int, int>();
            int[] ans = new int[len];
            foreach (int a in sortedArr)
            {
                ranks.TryAdd(a, ranks.Count + 1);
            }
            for (int i = 0; i < arr.Length; i++)
            {
                ans[i] = ranks[arr[i]];
            }
            return ans;
        }

    }
}
