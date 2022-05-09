using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo942
{
    public class Class942
    {
        public int[] DiStringMatch(string s)
        {
            int n = s.Length, lo = 0, hi = n;
            int[] perm = new int[n + 1];
            for (int i = 0; i < n; ++i)
            {
                perm[i] = s[i] == 'I' ? lo++ : hi--;
            }
            perm[n] = lo; // 最后剩下一个数，此时 lo == hi
            return perm;
        }

    }
}
