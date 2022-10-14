using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo940
{
    public class Class940
    {
        public int DistinctSubseqII(string s)
        {
            const int MOD = 1000000007;
            int[] last = new int[26];
            Array.Fill(last, -1);

            int n = s.Length;
            int[] f = new int[n];
            Array.Fill(f, 1);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (last[j] != -1)
                    {
                        f[i] = (f[i] + f[last[j]]) % MOD;
                    }
                }
                last[s[i] - 'a'] = i;
            }

            int ans = 0;
            for (int i = 0; i < 26; ++i)
            {
                if (last[i] != -1)
                {
                    ans = (ans + f[last[i]]) % MOD;
                }
            }
            return ans;
        }
    }
}
