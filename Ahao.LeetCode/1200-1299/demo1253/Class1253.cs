using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1253
{
    public class Class1253
    {
        public IList<IList<int>> ReconstructMatrix(int upper, int lower, int[] colsum)
        {
            IList<IList<int>> res = new List<IList<int>>();
            int sum = colsum.Sum();
            int twoCount = 0;

            int n = colsum.Length;
            int[] rowOne = new int[n];
            int[] rowTwo = new int[n];
            for (int i = 0; i < n; i++)
            {
                if (colsum[i] == 2)
                {
                    twoCount++;
                }
            }

            if (sum != upper + lower || Math.Min(upper, lower) < twoCount)
            {
                return res;
            }

            upper -= twoCount;
            lower -= twoCount;

            for (int i = 0; i < n; i++)
            {
                if (colsum[i] == 2)
                {
                    rowOne[i] = 1;
                    rowTwo[i] = 1;
                }
                else if (colsum[i] == 0)
                {
                    rowOne[i] = 0;
                    rowTwo[i] = 0;
                }
                else if (colsum[i] == 1)
                {
                    if (upper > 0)
                    {
                        rowOne[i] = 1;
                        rowTwo[i] = 0;
                        upper--;
                    }
                    else
                    {
                        rowOne[i] = 0;
                        rowTwo[i] = 1;
                        lower--;
                    }
                }

            }


            res.Add(rowOne.ToList());
            res.Add(rowTwo.ToList());
            return res;
        }

    }
}
