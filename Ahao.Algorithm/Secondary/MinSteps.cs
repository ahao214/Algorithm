using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 650. 只有两个键的键盘
    /// </summary>
    public class MinSteps
    {
        public int Method(int n)
        {
            int[] dp = new int[n + 1];

            //初始化: 每个dp值都可由 copy 'A' + paste n-1 个 'A'完成,即dp[j] = j
            for (int i = 0; i < n + 1; i++)
            {
                dp[i] = i;
            }

            //想要输出恰好 n 个字符,最多需要 copy n/2 向下取整个字符
            int maxCopy = n / 2;

            for (int i = 2; i <= maxCopy; i++)
            {
                dp[2 * i] = dp[i] + 2;
                for (int j = 3 * i; j < n + 1; j += i)
                {
                    dp[j] = dp[j - i] + 1;
                }
            }
            return dp[n];
        }
    }
}
