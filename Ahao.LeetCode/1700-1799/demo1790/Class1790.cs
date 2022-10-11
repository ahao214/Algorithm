using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1790
{
    public class Class1790
    {
        public bool AreAlmostEqual(string s1, string s2)
        {
            int n = s1.Length;
            IList<int> diff = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                if (s1[i] != s2[i])
                {
                    if (diff.Count >= 2)
                    {
                        return false;
                    }
                    diff.Add(i);
                }
            }
            if (diff.Count == 0)
            {
                return true;
            }
            if (diff.Count != 2)
            {
                return false;
            }
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
        }

    }
}
