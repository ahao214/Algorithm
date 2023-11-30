using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1657
{
    public class Class1657
    {
        public bool CloseStrings(string word1, string word2)
        {
            int[] count1 = new int[26], count2 = new int[26];
            foreach (char c in word1)
            {
                count1[c - 'a']++;
            }
            foreach (char c in word2)
            {
                count2[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0)
                {
                    return false;
                }
            }
            Array.Sort(count1);
            Array.Sort(count2);
            return Enumerable.SequenceEqual(count1, count2);
        }

    }
}
