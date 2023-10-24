using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2698
{
    public class Class2698
    {
        public int PunishmentNumber(int n)
        {
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (Check(i))
                    sum += i * i;
            }
            return sum;
        }

        private bool Check(int n)
        {
            string s = (n * n).ToString();
            int len = s.Length;
            if (len == 1) return n == int.Parse(s);
            //例如s=1296时，将s当作1,2,9,6 那么现在我们枚举这三个位置的逗号是否选择即可
            //我们可以用二进制111分别表示逗号是否选择，1为选择，0为不选
            //那么如何枚举二进制111之内的所有情况呢，我们枚举值（1<<3-1=7）内的所有非负整数即可
            int max = 1 << (len - 1);
            for (int i = 0; i < max; i++)
            {
                int sum = 0;
                int cutLen = 1;
                int temp = i;
                for (int j = len - 1; j >= 1; j--)
                {
                    int val = temp & 1;
                    temp = temp >> 1;
                    if (val == 1)
                    {
                        string subStr = s.Substring(j, cutLen);
                        sum += int.Parse(subStr);
                        if (sum > n) break;
                        cutLen = 1;
                    }
                    else
                    {
                        cutLen++;
                    }
                }
                if (sum > n) continue;
                sum += int.Parse(s.Substring(0, cutLen));
                if (sum == n) return true;
            }
            return false;
        }


        public int PunishmentNumber2(int n)
        {
            int res = 0;
            for (int i = 1; i <= n; i++)
            {
                string s = (i * i).ToString();
                if (DFS(s, 0, 0, i))
                {
                    res += i * i;
                }
            }
            return res;
        }

        public bool DFS(string s, int pos, int tot, int target)
        {
            if (pos == s.Length)
            {
                return tot == target;
            }
            int sum = 0;
            for (int i = pos; i < s.Length; i++)
            {
                sum = sum * 10 + s[i] - '0';
                if (sum + tot > target)
                {
                    break;
                }
                if (DFS(s, i + 1, sum + tot, target))
                {
                    return true;
                }
            }
            return false;
        }


    }
}
