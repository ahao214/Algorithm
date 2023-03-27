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

    }
}
