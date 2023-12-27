using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2735
{
    public class Class2735
    {

        public long MinCost(int[] nums, int x)
        {
            int n = nums.Length;
            int[] f = new int[n];
            Array.Copy(nums, 0, f, 0, n);
            long ans = GetSum(f);
            for (int k = 1; k < n; ++k)
            {
                for (int i = 0; i < n; ++i)
                {
                    f[i] = Math.Min(f[i], nums[(i + k) % n]);
                }
                ans = Math.Min(ans, (long)k * x + GetSum(f));
            }
            return ans;
        }

        public long GetSum(int[] f)
        {
            long sum = 0;
            foreach (int num in f)
            {
                sum += num;
            }
            return sum;
        }


        public long MinCost2(int[] nums, int x)
        {
            int n = nums.Length;
            // 找出 nums 中最小的元素，并用其为首元素构造一个新的数组
            int minIdx = 0;
            for (int i = 1; i < n; ++i)
            {
                if (nums[i] < nums[minIdx])
                {
                    minIdx = i;
                }
            }
            int[] tmp = new int[n];
            for (int i = 0; i < n; ++i)
            {
                tmp[i] = nums[(minIdx + i) % n];
            }
            Array.Copy(tmp, 0, nums, 0, n);

            int[] L = new int[n];
            int[] R = new int[n];
            L[0] = n - 1;
            // 循环来看，右侧 nums[0] 是更小的元素，但不一定是第一个更小的元素，需要用单调栈计算得到
            for (int i = 0; i < n; ++i)
            {
                R[i] = n - i - 1;
            }
            Stack<int> stack = new Stack<int>();
            stack.Push(0);
            for (int i = 1; i < n; ++i)
            {
                while (stack.Count > 0 && nums[i] < nums[stack.Peek()])
                {
                    R[stack.Peek()] = i - stack.Peek() - 1;
                    stack.Pop();
                }
                L[i] = i - stack.Peek() - 1;
                stack.Push(i);
            }

            long[] F = new long[n];

            // 进行操作需要的成本
            DiffTwice(F, 0, n - 1, x, 0);

            for (int i = 0; i < n; ++i)
            {
                int minv = Math.Min(L[i], R[i]);
                int maxv = Math.Max(L[i], R[i]);
                // 第一种情况，窗口数量 k+1，总和 nums[i] * k + nums[i]
                DiffTwice(F, 0, minv, nums[i], nums[i]);
                // 第二种情况，窗口数量 minv+1，总和 0 * k + nums[i] * (minv + 1)
                DiffTwice(F, minv + 1, maxv, 0, (long)nums[i] * (minv + 1));
                // 第三种情况，窗口数量 L[i]+R[i]-k+1，总和 -nums[i] * k + nums[i] * (L[i] + R[i] + 1)
                DiffTwice(F, maxv + 1, L[i] + R[i], -nums[i], (long)nums[i] * (L[i] + R[i] + 1));
            }

            // 计算两次前缀和
            for (int i = 0; i < 2; ++i)
            {
                long[] G = new long[n];
                G[0] = F[0];
                for (int j = 1; j < n; ++j)
                {
                    G[j] = G[j - 1] + F[j];
                }
                Array.Copy(G, 0, F, 0, n);
            }

            long minimum = long.MaxValue;
            foreach (long num in F)
            {
                minimum = Math.Min(minimum, num);
            }
            return minimum;
        }

        // 辅助函数，一次差分，将 F[l..r] 都增加 d
        public void DiffOnce(long[] F, int l, int r, long d)
        {
            if (l > r)
            {
                return;
            }
            int n = F.Length;
            if (l < n)
            {
                F[l] += d;
            }
            if (r + 1 < n)
            {
                F[r + 1] -= d;
            }
        }


        // 辅助函数，二次差分，将 F[l..r] 增加 ki + b，i 是下标
        public void DiffTwice(long[] F, int l, int r, long k, long b)
        {
            if (l > r)
            {
                return;
            }
            DiffOnce(F, l, l, k * l + b);
            DiffOnce(F, l + 1, r, k);
            DiffOnce(F, r + 1, r + 1, -(k * r + b));
        }


    }
}
