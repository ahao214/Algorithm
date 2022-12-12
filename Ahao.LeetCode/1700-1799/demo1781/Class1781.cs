using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1781
{
    public class Class1781
    {
        public int BeautySum(string s)
        {
            int res = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int[] cnt = new int[26];
                int maxFreq = 0;
                for (int j = i; j < s.Length; j++)
                {
                    cnt[s[j] - 'a']++;
                    maxFreq = Math.Max(maxFreq, cnt[s[j] - 'a']);
                    int minFreq = s.Length;
                    for (int k = 0; k < 26; k++)
                    {
                        if (cnt[k] > 0)
                        {
                            minFreq = Math.Min(minFreq, cnt[k]);
                        }
                    }
                    res += maxFreq - minFreq;
                }
            }
            return res;
        }
    }
}
