using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo383
{
    /// <summary>
    /// 383. 赎金信
    /// </summary>
    public class Class383
    {
        public bool CanConstruct(string ransomNote, string magazine)
        {
            if (ransomNote.Length > magazine.Length)
            {
                return false;
            }
            int[] cnt = new int[26];
            foreach (char c in magazine)
            {
                cnt[c - 'a']++;
            }
            foreach (char c in ransomNote)
            {
                cnt[c - 'a']--;
                if (cnt[c - 'a'] < 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
