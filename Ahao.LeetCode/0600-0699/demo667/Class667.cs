using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo667
{
    public class Class667
    {
        public int[] ConstructArray(int n, int k)
        {
            int[] answer = new int[n];
            int idx = 0;
            for (int i = 1; i < n - k; ++i)
            {
                answer[idx] = i;
                ++idx;
            }
            for (int i = n - k, j = n; i <= j; ++i, --j)
            {
                answer[idx] = i;
                ++idx;
                if (i != j)
                {
                    answer[idx] = j;
                    ++idx;
                }
            }
            return answer;
        }
    }
}
