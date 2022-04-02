using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo420
{
    public class Class420
    {
        public int StrongPasswordChecker(string password)
        {
            int n = password.Length;
            int hasLower = 0, hasUpper = 0, hasDigit = 0;
            foreach (char ch in password)
            {
                if (char.IsLower(ch))                
                    hasLower = 1;                
                else if (char.IsUpper(ch))             
                    hasUpper = 1;                
                else if (char.IsDigit(ch))                
                    hasDigit = 1;                
            }
            int categories = hasLower + hasUpper + hasDigit;

            if (n < 6)
            {
                return Math.Max(6 - n, 3 - categories);
            }
            else if (n <= 20)
            {
                int replace = 0;
                int cnt = 0;
                char cur = '#';

                foreach (char ch in password)
                {
                    if (ch == cur)
                    {
                        ++cnt;
                    }
                    else
                    {
                        replace += cnt / 3;
                        cnt = 1;
                        cur = ch;
                    }
                }
                replace += cnt / 3;
                return Math.Max(replace, 3 - categories);
            }
            else
            {
                // 替换次数和删除次数
                int replace = 0, remove = n - 20;
                // k mod 3 = 1 的组数，即删除 2 个字符可以减少 1 次替换操作
                int rm2 = 0;
                int cnt = 0;
                char cur = '#';

                foreach (char ch in password)
                {
                    if (ch == cur)
                    {
                        ++cnt;
                    }
                    else
                    {
                        if (remove > 0 && cnt >= 3)
                        {
                            if (cnt % 3 == 0)
                            {
                                // 如果是 k % 3 = 0 的组，那么优先删除 1 个字符，减少 1 次替换操作
                                --remove;
                                --replace;
                            }
                            else if (cnt % 3 == 1)
                            {
                                // 如果是 k % 3 = 1 的组，那么存下来备用
                                ++rm2;
                            }
                            // k % 3 = 2 的组无需显式考虑
                        }
                        replace += cnt / 3;
                        cnt = 1;
                        cur = ch;
                    }
                }
                if (remove > 0 && cnt >= 3)
                {
                    if (cnt % 3 == 0)
                    {
                        --remove;
                        --replace;
                    }
                    else if (cnt % 3 == 1)
                    {
                        ++rm2;
                    }
                }
                replace += cnt / 3;

                // 使用 k % 3 = 1 的组的数量，由剩余的替换次数、组数和剩余的删除次数共同决定
                int use2 = Math.Min(Math.Min(replace, rm2), remove / 2);
                replace -= use2;
                remove -= use2 * 2;
                // 由于每有一次替换次数就一定有 3 个连续相同的字符（k / 3 决定），因此这里可以直接计算出使用 k % 3 = 2 的组的数量
                int use3 = Math.Min(replace, remove / 3);
                replace -= use3;
                remove -= use3 * 3;
                return (n - 20) + Math.Max(replace, 3 - categories);
            }
        }

    }
}
