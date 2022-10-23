using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1768
{
    public class Class1768
    {
        public string MergeAlternately(string word1, string word2)
        {
            int m = word1.Length, n = word2.Length;
            int i = 0, j = 0;

            StringBuilder ans = new StringBuilder();
            while (i < m || j < n)
            {
                if (i < m)
                {
                    ans.Append(word1[i]);
                    ++i;
                }
                if (j < n)
                {
                    ans.Append(word2[j]);
                    ++j;
                }
            }
            return ans.ToString();
        }
    }
}
