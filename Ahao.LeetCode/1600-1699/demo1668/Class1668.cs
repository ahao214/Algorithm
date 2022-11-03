using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1668
{
    public class Class1668
    {
        public int MaxRepeating(string sequence, string word)
        {
            int n = sequence.Length, m = word.Length;
            if (n < m)
            {
                return 0;
            }

            int[] f = new int[n];
            for (int i = m - 1; i < n; ++i)
            {
                bool valid = true;
                for (int j = 0; j < m; ++j)
                {
                    if (sequence[i - m + j + 1] != word[j])
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
                }
            }

            return f.Max();
        }
    }
}
