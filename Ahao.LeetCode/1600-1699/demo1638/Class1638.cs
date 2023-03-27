using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1638
{
    public class Class1638
    {

        public int CountSubstrings(string s, string t)
        {
            int m = s.Length, n = t.Length;
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int diff = 0;
                    for (int k = 0; i + k < m && j + k < n; k++)
                    {
                        diff += s[i + k] == t[j + k] ? 0 : 1;
                        if (diff > 1)
                        {
                            break;
                        }
                        else if (diff == 1)
                        {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }


        public int CountSubstrings2(string s, string t)
        {
            int m = s.Length, n = t.Length;
            int[][] dpl = new int[m + 1][];
            int[][] dpr = new int[m + 1][];
            for (int i = 0; i <= m; i++)
            {
                dpl[i] = new int[n + 1];
                dpr[i] = new int[n + 1];
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dpl[i + 1][j + 1] = s[i] == t[j] ? (dpl[i][j] + 1) : 0;
                }
            }
            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    dpr[i][j] = s[i] == t[j] ? (dpr[i + 1][j + 1] + 1) : 0;
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (s[i] != t[j])
                    {
                        ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                    }
                }
            }
            return ans;
        }


    }
}
