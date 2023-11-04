using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo187
{
    public class Class187
    {
        const int L = 10;

        public IList<string> FindRepeatedDnaSequences(string s)
        {
            IList<string> ans = new List<string>();
            Dictionary<string, int> cnt = new Dictionary<string, int>();
            int n = s.Length;
            for (int i = 0; i <= n - L; ++i)
            {
                string sub = s.Substring(i, L);
                if (!cnt.ContainsKey(sub))
                {
                    cnt.Add(sub, 1);
                }
                else
                {
                    ++cnt[sub];
                }
                if (cnt[sub] == 2)
                {
                    ans.Add(sub);
                }
            }
            return ans;
        }



        //const int L = 10;
        Dictionary<char, int> bin = new Dictionary<char, int> {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
    };

        public IList<string> FindRepeatedDnaSequences2(string s)
        {
            IList<string> ans = new List<string>();
            int n = s.Length;
            if (n <= L)
            {
                return ans;
            }
            int x = 0;
            for (int i = 0; i < L - 1; ++i)
            {
                x = (x << 2) | bin[s[i]];
            }
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            for (int i = 0; i <= n - L; ++i)
            {
                x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
                if (!cnt.ContainsKey(x))
                {
                    cnt.Add(x, 1);
                }
                else
                {
                    ++cnt[x];
                }
                if (cnt[x] == 2)
                {
                    ans.Add(s.Substring(i, L));
                }
            }
            return ans;
        }



    }
}
