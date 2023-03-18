using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1625
{
    public class Class1625
    {
        public string FindLexSmallestString(string s, int a, int b)
        {
            int n = s.Length;
            bool[] vis = new bool[n];
            string res = s;
            // 将 s 延长一倍，方便截取轮转后的字符串 t
            s = s + s;
            for (int i = 0; !vis[i]; i = (i + b) % n)
            {
                vis[i] = true;
                for (int j = 0; j < 10; j++)
                {
                    int kLimit = b % 2 == 0 ? 0 : 9;
                    for (int k = 0; k <= kLimit; k++)
                    {
                        // 每次进行累加之前，重新截取 t
                        char[] t = s.Substring(i, n).ToCharArray();
                        for (int p = 1; p < n; p += 2)
                        {
                            t[p] = (char)('0' + (t[p] - '0' + j * a) % 10);
                        }
                        for (int p = 0; p < n; p += 2)
                        {
                            t[p] = (char)('0' + (t[p] - '0' + k * a) % 10);
                        }
                        string tStr = new string(t);
                        if (tStr.CompareTo(res) < 0)
                        {
                            res = tStr;
                        }
                    }
                }
            }
            return res;
        }
    }
}
