using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo788
{
    public class Class788
    {
        //方法一：枚举每一个数
        static int[] check = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };

        public int RotatedDigits(int n)
        {
            int ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                string num = i.ToString();
                bool valid = true, diff = false;
                foreach (char ch in num)
                {
                    if (check[ch - '0'] == -1)
                    {
                        valid = false;
                    }
                    else if (check[ch - '0'] == 1)
                    {
                        diff = true;
                    }
                }
                if (valid && diff)
                {
                    ++ans;
                }
            }
            return ans;
        }


        //方法二：数位动态规划
        static int[] check2 = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };
        int[,,] memo = new int[5, 2, 2];
        IList<int> digits = new List<int>();

        public int RotatedDigits2(int n)
        {
            while (n != 0)
            {
                digits.Add(n % 10);
                n /= 10;
            }
            for (int i = 0, j = digits.Count - 1; i < j; ++i, --j)
            {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }

            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    for (int k = 0; k < 2; ++k)
                    {
                        memo[i, j, k] = -1;
                    }
                }
            }

            int ans = DFS(0, 1, 0);
            return ans;
        }

        public int DFS(int pos, int bound, int diff)
        {
            if (pos == digits.Count)
            {
                return diff;
            }
            if (memo[pos, bound, diff] != -1)
            {
                return memo[pos, bound, diff];
            }

            int ret = 0;
            for (int i = 0; i <= (bound != 0 ? digits[pos] : 9); ++i)
            {
                if (check[i] != -1)
                {
                    ret += DFS(
                        pos + 1,
                        bound != 0 && i == digits[pos] ? 1 : 0,
                        diff != 0 || check[i] == 1 ? 1 : 0
                    );
                }
            }
            return memo[pos, bound, diff] = ret;
        }

    }
}
