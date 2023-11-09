using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2300
{
    public class Class2300
    {
        public int[] SuccessfulPairs(int[] spells, int[] potions, long success)
        {
            int n = spells.Length;
            int m = potions.Length;
            int[] result = new int[n];
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < m; j++)
                {
                    if (spells[i] * potions[j] >= success)
                    {
                        count++;
                    }
                }
                result[i] = count;
            }
            return result;
        }
    }
}
