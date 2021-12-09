using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo748
{
    /// <summary>
    /// 748. 最短补全词
    /// </summary>
    public class Class748
    {
        public string ShortestCompletingWord(string licensePlate, string[] words)
        {
            int[] cnt = new int[26];
            foreach (char ch in licensePlate)
            {
                if (char.IsLetter(ch))
                {
                    ++cnt[char.ToLower(ch) - 'a'];
                }
            }
            int idx = -1;
            for (int i = 0; i < words.Length; i++)
            {
                int[] c = new int[26];
                foreach (char ch in words[i])
                {
                    ++c[ch - 'a'];
                }
                bool ok = true;
                for (int j = 0; j < 26; j++)
                {
                    if (c[j] < cnt[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok && (idx <= || words[i].Length < words[idx].Length))
                {
                    idx = i;
                }
            }
            return words[idx];
        }
    }
}
