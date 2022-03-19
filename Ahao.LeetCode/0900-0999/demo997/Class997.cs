using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo997
{
    /// <summary>
    /// 997. 找到小镇的法官
    /// </summary>
    public class Class997
    {
        public int FindJudge(int n, int[][] trust)
        {
            //被信任的人
            int[] first = new int[n + 1];
            int[] second = new int[n + 1];
            foreach (int[] deg in trust)
            {
                first[deg[1]]++;
                second[deg[0]]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (first[i] == n - 1 && second[i] == 0)
                {
                    return i;
                }
            }
            return -1;
        }
    }
}
