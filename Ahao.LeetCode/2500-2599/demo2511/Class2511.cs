using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2511
{
    public class Class2511
    {
        public int CaptureForts(int[] forts)
        {
            int res = 0;
            int countZero = 0;
            int sum = forts[0];
            for (int i = 1; i < forts.Length; i++)
            {
                sum += forts[i];
                if (forts[i] == 0 && sum != 0)
                {
                    countZero++;
                }
                else
                {
                    if (sum == 0)
                    {
                        res = Math.Max(res, countZero);
                        countZero = 0;
                        sum = forts[i];
                    }
                    else
                    {
                        sum = forts[i];
                        countZero = 0;
                    }
                }
            }
            return res;
        }

    }
}
