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
            Array.Sort(potions);
            int n = spells.Length, m = potions.Length;
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
            {
                long t = (success + spells[i] - 1) / spells[i] - 1;
                res[i] = m - BinarySearch(potions, 0, m - 1, t);
            }
            return res;
        }

        public int BinarySearch(int[] arr, int lo, int hi, long target)
        {
            int res = hi + 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] > target)
                {
                    res = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            return res;
        }


        public int[] SuccessfulPairs2(int[] spells, int[] potions, long success)
        {
            int n = spells.Length, m = potions.Length;
            int[] res = new int[n];
            int[][] idx = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                idx[i] = new int[2];
                idx[i][0] = spells[i];
                idx[i][1] = i;
            }
            Array.Sort(potions);
            for (int i = 0, j = m - 1; i < j; ++i, --j)
            {
                int temp = potions[i];
                potions[i] = potions[j];
                potions[j] = temp;
            }
            Array.Sort(idx, (a, b) => a[0] - b[0]);
            for (int i = 0, j = 0; i < n; ++i)
            {
                int p = idx[i][1];
                int v = idx[i][0];
                while (j < m && (long)potions[j] * v >= success)
                {
                    ++j;
                }
                res[p] = j;
            }
            return res;
        }


    }
}
