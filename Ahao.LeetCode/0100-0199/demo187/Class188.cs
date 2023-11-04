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





    }
}
