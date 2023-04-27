using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1048
{
    public class Class1048
    {
        public int LongestStrChain(string[] words)
        {
            IDictionary<string, int> cnt = new Dictionary<string, int>();
            Array.Sort(words, (a, b) => a.Length - b.Length);
            int res = 0;
            foreach (string word in words)
            {
                if (cnt.ContainsKey(word))
                {
                    cnt[word] = 1;
                }
                else
                {
                    cnt.Add(word, 1);
                }
                for (int i = 0; i < word.Length; i++)
                {
                    string prev = word.Substring(0, i) + word.Substring(i + 1);
                    if (cnt.ContainsKey(prev))
                    {
                        cnt[word] = Math.Max(cnt[word], cnt[prev] + 1);
                    }
                }
                res = Math.Max(res, cnt[word]);
            }
            return res;
        }

    }
}
