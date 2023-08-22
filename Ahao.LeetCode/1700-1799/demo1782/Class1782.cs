using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1782
{
    public class Class1782
    {
        public int[] CountPairs(int n, int[][] edges, int[] queries)
        {
            int[] degree = new int[n];
            IDictionary<int, int> cnt = new Dictionary<int, int>();
            foreach (int[] edge in edges)
            {
                int x = edge[0] - 1, y = edge[1] - 1;
                if (x > y)
                {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                degree[x]++;
                degree[y]++;
                cnt.TryAdd(x * n + y, 0);
                cnt[x * n + y]++;
            }

            int[] arr = new int[n];
            Array.Copy(degree, 0, arr, 0, n);
            int[] ans = new int[queries.Length];
            Array.Sort(arr);
            for (int k = 0; k < queries.Length; k++)
            {
                int bound = queries[k], total = 0;
                for (int i = 0; i < n; i++)
                {
                    int j = BinarySearch(arr, i + 1, n - 1, bound - arr[i]);
                    total += n - j;
                }
                foreach (KeyValuePair<int, int> pair in cnt)
                {
                    int val = pair.Key, freq = pair.Value;
                    int x = val / n, y = val % n;
                    if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound)
                    {
                        total--;
                    }
                }
                ans[k] = total;
            }

            return ans;
        }

        public int BinarySearch(int[] arr, int left, int right, int target)
        {
            int ans = right + 1;
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                if (arr[mid] <= target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                    ans = mid;
                }
            }
            return ans;
        }




        public int[] CountPairs2(int n, int[][] edges, int[] queries)
        {
            int[] degree = new int[n];
            IDictionary<int, int> cnt = new Dictionary<int, int>();
            foreach (int[] edge in edges)
            {
                int x = edge[0] - 1, y = edge[1] - 1;
                if (x > y)
                {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                degree[x]++;
                degree[y]++;
                cnt.TryAdd(x * n + y, 0);
                cnt[x * n + y]++;
            }

            int[] arr = new int[n];
            Array.Copy(degree, 0, arr, 0, n);
            int[] ans = new int[queries.Length];
            Array.Sort(arr);
            for (int k = 0; k < queries.Length; k++)
            {
                int bound = queries[k], total = 0;
                for (int i = 0, j = n - 1; i < n; i++)
                {
                    while (j > i && arr[i] + arr[j] > bound)
                    {
                        j--;
                    }
                    total += n - 1 - Math.Max(i, j);
                }
                foreach (KeyValuePair<int, int> pair in cnt)
                {
                    int val = pair.Key, freq = pair.Value;
                    int x = val / n, y = val % n;
                    if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound)
                    {
                        total--;
                    }
                }
                ans[k] = total;
            }

            return ans;
        }




    }
}
