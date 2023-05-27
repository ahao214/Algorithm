using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1439
{
    public class Class1439
    {

        public int KthSmallest(int[][] mat, int k)
        {
            int m = mat.Length;
            int[] prev = mat[0];
            for (int i = 1; i < m; ++i)
            {
                prev = Merge(prev, mat[i], k);
            }
            return prev[k - 1];
        }

        public int[] Merge(int[] f, int[] g, int k)
        {
            if (g.Length > f.Length)
            {
                return Merge(g, f, k);
            }

            PriorityQueue<int[], int> pq = new PriorityQueue<int[], int>();
            for (int i = 0; i < g.Length; ++i)
            {
                pq.Enqueue(new int[] { 0, i, f[0] + g[i] }, f[0] + g[i]);
            }

            IList<int> list = new List<int>();
            while (k > 0 && pq.Count > 0)
            {
                int[] entry = pq.Dequeue();
                list.Add(entry[2]);
                if (entry[0] + 1 < f.Length)
                {
                    pq.Enqueue(new int[] { entry[0] + 1, entry[1], f[entry[0] + 1] + g[entry[1]] }, f[entry[0] + 1] + g[entry[1]]);
                }
                --k;
            }

            return list.ToArray();
        }



        public int KthSmallest2(int[][] mat, int k)
        {
            int m = mat.Length;
            int[] prev = mat[0];
            for (int i = 1; i < m; ++i)
            {
                prev = Merge2(prev, mat[i], k);
            }
            return prev[k - 1];
        }

        public int[] Merge2(int[] f, int[] g, int k)
        {
            int left = f[0] + g[0], right = f[f.Length - 1] + g[g.Length - 1], thres = 0;
            k = Math.Min(k, f.Length * g.Length);
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int rptr = g.Length - 1, cnt = 0;
                for (int lptr = 0; lptr < f.Length; ++lptr)
                {
                    while (rptr >= 0 && f[lptr] + g[rptr] > mid)
                    {
                        --rptr;
                    }
                    cnt += rptr + 1;
                }
                if (cnt >= k)
                {
                    thres = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            IList<int> list = new List<int>();
            int index = 0;
            for (int i = 0; i < f.Length; ++i)
            {
                for (int j = 0; j < g.Length; ++j)
                {
                    int sum = f[i] + g[j];
                    if (sum < thres)
                    {
                        list.Add(sum);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            while (list.Count < k)
            {
                list.Add(thres);
            }
            int[] ans = list.ToArray();
            Array.Sort(ans);
            return ans;
        }
    }
}
