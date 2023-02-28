using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2363
{
    public class Class2363
    {

        public IList<IList<int>> MergeSimilarItems(int[][] items1, int[][] items2)
        {
            IDictionary<int, int> dictionary = new Dictionary<int, int>();
            foreach (int[] v in items1)
            {
                dictionary.TryAdd(v[0], 0);
                dictionary[v[0]] += v[1];
            }
            foreach (int[] v in items2)
            {
                dictionary.TryAdd(v[0], 0);
                dictionary[v[0]] += v[1];
            }

            IList<IList<int>> res = new List<IList<int>>();
            foreach (KeyValuePair<int, int> kv in dictionary)
            {
                int k = kv.Key, v = kv.Value;
                res.Add(new List<int> { k, v });
            }
            ((List<IList<int>>)res).Sort((a, b) => a[0] - b[0]);
            return res;
        }


        public IList<IList<int>> MergeSimilarItems2(int[][] items1, int[][] items2)
        {
            KeyValuePair<int, int> GetKV(int[] t)
            {
                return new KeyValuePair<int, int>(t[0], t[1]);
            }
            var a = items1.Select(GetKV).ToList();
            var b = items2.Select(GetKV).ToList();
            a.AddRange(b);
            return a.GroupBy(a => a.Key, (n, g) => new List<int> { n, g.Sum(t => t.Value) }).OrderBy(x => x[0]).Cast<IList<int>>().ToList();

        }



        public IList<IList<int>> MergeSimilarItems3(int[][] items1, int[][] items2)
        {
            int[] table = new int[1001];
            int n1 = items1.Length, n2 = items2.Length;
            for (int i = 0; i < n1; i++)
                table[items1[i][0]] += items1[i][1];
            for (int i = 0; i < n2; i++)
                table[items2[i][0]] += items2[i][1];

            IList<IList<int>> res = new List<IList<int>>();
            for (int i = 0; i < 1001; i++)
            {
                if (table[i] > 0)
                    res.Add(new List<int>() { i, table[i] });
            }
            return res;
        }



    }
}
