using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo506
{
    /// <summary>
    /// 506. 相对名次
    /// </summary>
    public class Class506
    {
        public string[] FindRelativeRanks(int[] score)
        {
            int n = score.Length;
            string[] desc = { "Gold Medal", "Silver Medal", "Bronze Medal" };
            int[][] arr = new int[n][];
            for (int i = 0; i < n; i++)
            {
                arr[i] = new int[2];
                arr[i][0] = score[i];
                arr[i][1] = i;
            }

            Array.Sort(arr, (a, b) => b[0] - a[0]);
            string[] result = new string[n];
            for (int i = 0; i < n; i++)
            {
                if (i < 3)
                {
                    result[arr[i][1]] = desc[i];
                }
                else
                {
                    result[arr[i][1]] = (i + 1).ToString();
                }
            }
            return result;
        }
    }
}
