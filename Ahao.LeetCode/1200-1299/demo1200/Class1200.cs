using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1200
{
    public class Class1200
    {
        public IList<IList<int>> MinimumAbsDifference(int[] arr)
        {
            int n = arr.Length;
            Array.Sort(arr);

            int best = int.MaxValue;
            IList<IList<int>> ans = new List<IList<int>>();
            for (int i = 0; i < n - 1; ++i)
            {
                int delta = arr[i + 1] - arr[i];
                if (delta < best)
                {
                    best = delta;
                    ans.Clear();
                    IList<int> pair = new List<int>();
                    pair.Add(arr[i]);
                    pair.Add(arr[i + 1]);
                    ans.Add(pair);
                }
                else if (delta == best)
                {
                    IList<int> pair = new List<int>();
                    pair.Add(arr[i]);
                    pair.Add(arr[i + 1]);
                    ans.Add(pair);
                }
            }

            return ans;
        }

    }
}
