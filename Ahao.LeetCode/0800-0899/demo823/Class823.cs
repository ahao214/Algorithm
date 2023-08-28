using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo823
{
    public class Class823
    {
        public int NumFactoredBinaryTrees(int[] arr)
        {
            Array.Sort(arr);
            int n = arr.Length;
            long[] dp = new long[n];
            long res = 0, mod = 1000000007;
            for (int i = 0; i < n; i++)
            {
                dp[i] = 1;
                for (int left = 0, right = i - 1; left <= right; left++)
                {
                    while (right >= left && (long)arr[left] * arr[right] > arr[i])
                    {
                        right--;
                    }
                    if (right >= left && (long)arr[left] * arr[right] == arr[i])
                    {
                        if (right != left)
                        {
                            dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
                        }
                        else
                        {
                            dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
                        }
                    }
                }
                res = (res + dp[i]) % mod;
            }
            return (int)res;
        }




        public int NumFactoredBinaryTrees2(int[] arr)
        {
            const int MODULO = 1000000007;
            Array.Sort(arr);
            IDictionary<int, int> indices = new Dictionary<int, int>();
            int n = arr.Length;
            for (int i = 0; i < n; i++)
            {
                indices.Add(arr[i], i);
            }
            long[] dp = new long[n];
            Array.Fill(dp, 1);
            for (int i = 1; i < n; i++)
            {
                int root = arr[i];
                for (int j = 0; j < i && (long)arr[j] * arr[j] <= arr[i]; j++)
                {
                    int left = arr[j];
                    if (root % left == 0 && indices.ContainsKey(root / left))
                    {
                        int right = root / left;
                        int k = indices[right];
                        if (j == k)
                        {
                            dp[i] = (dp[i] + dp[j] * dp[k]) % MODULO;
                        }
                        else
                        {
                            dp[i] = (dp[i] + dp[j] * dp[k] * 2) % MODULO;
                        }
                    }
                }
            }
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                total = (total + (int)dp[i]) % MODULO;
            }
            return total;
        }




        public int NumFactoredBinaryTrees3(int[] arr)
        {
            const int MOD = 1_000_000_007;
            long res = 0;
            var dict = new Dictionary<int, long>();
            Array.Sort(arr);
            foreach (var num in arr)
            {
                long value = 1;
                foreach (var key in dict.Keys)
                {
                    if (num % key == 0 && dict.ContainsKey(num / key))
                    {
                        value += dict[key] * dict[num / key];
                    }
                }
                dict.Add(num, value);
                res += value;
                res %= MOD;
            }
            return (int)res;
        }


    }
}
