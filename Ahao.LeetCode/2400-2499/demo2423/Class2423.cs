using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2423
{
    public class Class2423
    {

        public bool EqualFrequency(string word)
        {
            int[] charCount = new int[26];
            foreach (char c in word)
            {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (charCount[i] == 0)
                {
                    continue;
                }
                charCount[i]--;
                HashSet<int> frequency = new HashSet<int>();
                foreach (int f in charCount)
                {
                    if (f > 0)
                    {
                        frequency.Add(f);
                    }
                }
                if (frequency.Count == 1)
                {
                    return true;
                }
                charCount[i]++;
            }
            return false;
        }



        public bool EqualFrequency2(string word)
        {
            int[] charCount = new int[26];
            foreach (char c in word)
            {
                charCount[c - 'a'] += 1;
            }
            Dictionary<int, int> freqCount = new Dictionary<int, int>();
            foreach (int c in charCount)
            {
                if (c > 0)
                {
                    if (freqCount.ContainsKey(c))
                    {
                        freqCount[c] += 1;
                    }
                    else
                    {
                        freqCount.Add(c, 1);
                    }
                }
            }
            foreach (int c in charCount)
            {
                if (c == 0)
                {
                    continue;
                }
                freqCount[c] -= 1;
                if (freqCount[c] == 0)
                {
                    freqCount.Remove(c);
                }
                if (c - 1 > 0)
                {
                    if (freqCount.ContainsKey(c - 1))
                    {
                        freqCount[c - 1] += 1;
                    }
                    else
                    {
                        freqCount.Add(c - 1, 1);
                    }
                }
                if (freqCount.Count == 1)
                {
                    return true;
                }
                if (c - 1 > 0)
                {
                    freqCount[c - 1] -= 1;
                    if (freqCount[c - 1] == 0)
                    {
                        freqCount.Remove(c - 1);
                    }
                }
                if (freqCount.ContainsKey(c))
                {
                    freqCount[c] += 1;
                }
                else
                {
                    freqCount.Add(c, 1);
                }
            }
            return false;
        }


    }
}
