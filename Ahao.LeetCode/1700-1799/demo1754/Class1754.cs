using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1754
{
    public class Class1754
    {
        public string LargestMerge(string word1, string word2)
        {
            StringBuilder merge = new StringBuilder();
            int i = 0, j = 0;
            while (i < word1.Length || j < word2.Length)
            {
                if (i < word1.Length && word1.Substring(i).CompareTo(word2.Substring(j)) > 0)
                {
                    merge.Append(word1[i]);
                    i++;
                }
                else
                {
                    merge.Append(word2[j]);
                    j++;
                }
            }
            return merge.ToString();
        }
    }
}
