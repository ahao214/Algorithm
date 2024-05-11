using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2645
{
    public class Class2645
    {
        public int AddMinimum(string word)
        {
            int n = word.Length;
            int[] d = new int[n + 1];
            for (int i = 1; i <= n; i++)
            {
                d[i] = d[i - 1] + 2;
                if (i > 1 && word[i - 1] > word[i - 2])
                {
                    d[i] = d[i - 1] - 1;
                }
            }
            return d[n];
        }


        public int AddMinimum2(string word)
        {
            int n = word.Length;
            int res = word[0] - word[n - 1] + 2;
            for (int i = 1; i < n; i++)
            {
                res += (word[i] - word[i - 1] + 2) % 3;
            }
            return res;
        }


        public int AddMinimum3(string word)
        {
            int n = word.Length, cnt = 1;
            for (int i = 1; i < n; i++)
            {
                if (word[i] <= word[i - 1])
                {
                    cnt++;
                }
            }
            return cnt * 3 - n;
        }


    }
}
