using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo312
{
    /// <summary>
    /// 312. 戳气球
    /// </summary>
    public class Class312
    {
        public int MaxCoins(int[] nums)
        {
            int n = nums.Length;
            //定义一个新的数组，长度为n+2
            int[] balls = new int[n + 2];
            balls[0] = 1;
            balls[n + 1] = 1;
            for (int i = 0; i < n; i++)
            {
                balls[i + 1] = nums[i];
            }
            //nums=[2,3,5,7]
            //balls=[1,2,3,5,7,1]
            return Score(balls, 1, n);
        }


        public int Score(int[] balls, int L, int R)
        {
            //只剩下一个气球的时候
            if (L == R)
            {
                return balls[L - 1] * balls[L] * balls[R + 1];
            }

            //L...R上不止一个气球
            //L位置的气球最后打破
            int pLeft = Score(balls, L + 1, R) + balls[L - 1] * balls[L] * balls[R + 1];

            //R位置的气球最后打破
            int pRight = Score(balls, L, R - 1) + balls[L - 1] * balls[R] * balls[R + 1];

            int result = Math.Max(pLeft, pRight);

            //L...R中间的随便一个位置的气球最后打破
            for (int mid = L + 1; mid < R; mid++)
            {
                int pMid = Score(balls, L, mid - 1) + Score(balls, mid + 1, R) + balls[L - 1] * balls[mid] * balls[R + 1];
                result = Math.Max(result, pMid);
            }

            return result;
        }


        public static int maxCoins2(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }
            if (nums.Length == 1)
            {
                return nums[0];
            }
            int N = nums.Length;
            int[] help = new int[N + 2];
            help[0] = 1;
            help[N + 1] = 1;
            for (int i = 0; i < N; i++)
            {
                help[i + 1] = nums[i];
            }
            int[,] dp = new int[N + 2, N + 2];
            for (int i = 1; i <= N; i++)
            {
                dp[i, i] = help[i - 1] * help[i] * help[i + 1];
            }
            for (int L = N; L >= 1; L--)
            {
                for (int R = L + 1; R <= N; R++)
                {
                    int ans = help[L - 1] * help[L] * help[R + 1] + dp[L + 1, R];
                    ans = Math.Max(ans, help[L - 1] * help[R] * help[R + 1] + dp[L, R - 1]);
                    for (int i = L + 1; i < R; i++)
                    {
                        ans = Math.Max(ans, help[L - 1] * help[i] * help[R + 1] + dp[L, i - 1] + dp[i + 1, R]);
                    }
                    dp[L, R] = ans;
                }
            }
            return dp[1, N];
        }
    }
}
