using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo907
{
    public class Class907
    {
        //单调栈 
        public int SumSubarrayMins(int[] arr)
        {
            int n = arr.Length;
            Stack<int> monoStack = new Stack<int>();
            int[] left = new int[n];
            int[] right = new int[n];
            for (int i = 0; i < n; i++)
            {
                while (monoStack.Count > 0 && arr[i] <= arr[monoStack.Peek()])
                {
                    monoStack.Pop();
                }
                left[i] = i - (monoStack.Count == 0 ? -1 : monoStack.Peek());
                monoStack.Push(i);
            }
            monoStack.Clear();
            for (int i = n - 1; i >= 0; i--)
            {
                while (monoStack.Count > 0 && arr[i] < arr[monoStack.Peek()])
                {
                    monoStack.Pop();
                }
                right[i] = (monoStack.Count == 0 ? n : monoStack.Peek()) - i;
                monoStack.Push(i);
            }
            long ans = 0;
            const int MOD = 1000000007;
            for (int i = 0; i < n; i++)
            {
                ans = (ans + (long)left[i] * right[i] * arr[i]) % MOD;
            }
            return (int)ans;
        }

        //动态规划
        public int SumSubarrayMins2(int[] arr)
        {
            int n = arr.Length;
            long ans = 0;
            const int MOD = 1000000007;
            Stack<int> monoStack = new Stack<int>();
            int[] dp = new int[n];
            for (int i = 0; i < n; i++)
            {
                while (monoStack.Count > 0 && arr[monoStack.Peek()] > arr[i])
                {
                    monoStack.Pop();
                }
                int k = monoStack.Count == 0 ? (i + 1) : (i - monoStack.Peek());
                dp[i] = k * arr[i] + (monoStack.Count == 0 ? 0 : dp[i - k]);
                ans = (ans + dp[i]) % MOD;
                monoStack.Push(i);
            }
            return (int)ans;
        }


    }
}
