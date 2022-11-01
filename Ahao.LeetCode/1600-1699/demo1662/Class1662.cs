using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1662
{
    public class Class1662
    {
        public bool ArrayStringsAreEqual(string[] word1, string[] word2)
        {
            return Join(word1).Equals(Join(word2));
        }

        public string Join(string[] words)
        {
            StringBuilder ret = new StringBuilder();
            foreach (string s in words)
            {
                ret.Append(s);
            }
            return ret.ToString();
        }




        public bool ArrayStringsAreEqual2(string[] word1, string[] word2)
        {
            int p1 = 0, p2 = 0, i = 0, j = 0;
            while (p1 < word1.Length && p2 < word2.Length)
            {
                if (word1[p1][i] != word2[p2][j])
                {
                    return false;
                }
                i++;
                if (i == word1[p1].Length)
                {
                    p1++;
                    i = 0;
                }
                j++;
                if (j == word2[p2].Length)
                {
                    p2++;
                    j = 0;
                }
            }
            return p1 == word1.Length && p2 == word2.Length;
        }

    }
}
