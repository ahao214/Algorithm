using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo242
{
    public class Class242
    {
        public bool IsAnagram(string s, string t)
        {
            if (s == null || t == null || s.Length != t.Length)
            {
                return false;
            }

            int[] counts = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                counts[s[i] - 'a']++;
            }
            for (int i = 0; i < t.Length; i++)
            {
                if (--counts[t[i] - 'a'] < 0)
                    return false;
            }
            return true;
        }
    }
}
