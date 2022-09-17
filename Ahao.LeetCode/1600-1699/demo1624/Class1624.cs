using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1624
{
    public class Class1624
    {
        public int MaxLengthBetweenEqualCharacters(string s)
        {
            int[] firstIndex = new int[26];
            Array.Fill(firstIndex, -1);
            int maxLength = -1;
            for (int i = 0; i < s.Length; i++)
            {
                if (firstIndex[s[i] - 'a'] < 0)
                {
                    firstIndex[s[i] - 'a'] = i;
                }
                else
                {
                    maxLength = Math.Max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
                }
            }
            return maxLength;
        }

        public int MaxLengthBetweenEqualCharacters2(string s)
        {
            int maxLength = -1;
            int n = s.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] == s[j])
                    {
                        maxLength = Math.Max(maxLength, j - i - 1);
                    }
                }
            }

            return maxLength;
        }
    }
}
