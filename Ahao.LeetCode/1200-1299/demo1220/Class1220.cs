using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1220
{
    public class Class1220
    {
        public int CountVowelPermutation(int n)
        {
            long mod = 1000000007;
            long[] dp = new long[5];
            long[] ndp = new long[5];
            for (int i = 0; i < 5; ++i)
            {
                dp[i] = 1;
            }
            for (int i = 2; i <= n; ++i)
            {
                /* a前面可以为e,u,i */
                ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
                /* e前面可以为a,i */
                ndp[1] = (dp[0] + dp[2]) % mod;
                /* i前面可以为e,o */
                ndp[2] = (dp[1] + dp[3]) % mod;
                /* o前面可以为i */
                ndp[3] = dp[2];
                /* u前面可以为i,o */
                ndp[4] = (dp[2] + dp[3]) % mod;
                Array.Copy(ndp, 0, dp, 0, 5);
            }
            long ans = 0;
            for (int i = 0; i < 5; ++i)
            {
                ans = (ans + dp[i]) % mod;
            }
            return (int)ans;
        }
    }
}
