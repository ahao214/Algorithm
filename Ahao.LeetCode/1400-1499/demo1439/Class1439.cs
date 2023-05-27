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




        private int m, n, k;
        private int[][] mat;
        // 计算小于等于当前数组和的数量
        private int cnt = 0;
        public int kthSmallest3(int[][] mat, int k)
        {
            this.k = k;
            this.mat = mat;
            m = mat.Length;
            n = mat[0].Length;
            // 搜索范围
            int left = 0, right = 0;
            for (int i = 0; i < m; i++)
            {
                left += mat[i][0];
                right += mat[i][n - 1];
            }
            // 把最小值设为初始值
            int init = left;
            while (left <= right)
            {
                int mid = left - (left - right) / 2;
                // 初始值也算一个可行解
                cnt = 1;
                dfs(0, init, mid);
                // 对应数组和大了，向左收缩
                if (cnt >= k) right = mid - 1;
                // 对应数组和小了，向右收缩
                else left = mid + 1;
            }
            return left;
        }

        // DFS 计算 小于等于 target 的数量
        private void dfs(int row, int sum, int target)
        {
            // 特殊情况，直接返回
            // sum > target：当前数组和大于 target
            // cnt > k：当前小于等于 target 的数量大于 k
            // row >= m：已经到达最后一行 (结束条件)
            if (sum > target || cnt > k || row >= m) return;
            // 不做交换
            dfs(row + 1, sum, target);
            // 分别与 [1, n-1] 交换
            for (int i = 1; i < n; i++)
            {
                // 更新数组和：减去「第一个元素」，加上「要交换的元素」
                int newSum = sum - mat[row][0] + mat[row][i];
                // 交换后的数组和大于 target，直接跳出循环
                // 原因：由于每行元素递增，所以当前元素大了，该行后面的元素肯定也大了
                if (newSum > target) break;
                // 满足要求，cnt + 1
                cnt++;
                // 搜索下一行
                dfs(row + 1, newSum, target);
            }
        }



    }
}
