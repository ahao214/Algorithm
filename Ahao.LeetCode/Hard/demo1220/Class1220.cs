using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1220
{
    /*
     1220. 统计元音字母序列的数目
    给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

    字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
    每个元音 'a' 后面都只能跟着 'e'
    每个元音 'e' 后面只能跟着 'a' 或者是 'i'
    每个元音 'i' 后面 不能 再跟着另一个 'i'
    每个元音 'o' 后面只能跟着 'i' 或者是 'u'
    每个元音 'u' 后面只能跟着 'a'
    由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。
     */
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
