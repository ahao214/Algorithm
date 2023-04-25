using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2418
{
    public class Class2418
    {

        public string[] SortPeople(string[] names, int[] heights)
        {
            int n = names.Length;
            int[] indices = new int[n];
            for (int i = 0; i < n; i++)
            {
                indices[i] = i;
            }
            Array.Sort(indices, (a, b) => heights[b] - heights[a]);
            string[] res = new string[n];
            for (int i = 0; i < n; i++)
            {
                res[i] = names[indices[i]];
            }
            return res;
        }



        public string[] SortPeople2(string[] names, int[] heights)
        {
            return heights.Select((t, index) => new KeyValuePair<int, int>(t, index)).OrderByDescending(x => x.Key).Select(t => names[t.Value]).ToArray();

        }
        public string[] SortPeople3(string[] names, int[] heights)
        {
            int n = names.Length;
            string[] res = new string[n];
            IDictionary<int, string> dict = new Dictionary<int, string>();
            for (int i = 0; i < n; i++)
            {
                dict.Add(heights[i], names[i]);
            }

            var items = dict.OrderByDescending(t => t.Key);
            int idx = 0;
            foreach (var item in items)
            {
                res[idx] = item.Value;
                idx++;
            }
            return res;
        }

    }
}
