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


        public IList<IList<int>> ReconstructMatrix2(int upper, int lower, int[] colsum)
        {
            int n = colsum.Length;
            int sum = 0, two = 0;
            for (int i = 0; i < n; ++i)
            {
                if (colsum[i] == 2)
                {
                    ++two;
                }
                sum += colsum[i];
            }
            if (sum != upper + lower || Math.Min(upper, lower) < two)
            {
                return new List<IList<int>>();
            }
            upper -= two;
            lower -= two;
            IList<IList<int>> res = new List<IList<int>>();
            for (int i = 0; i < 2; ++i)
            {
                res.Add(new List<int>());
            }
            for (int i = 0; i < n; ++i)
            {
                if (colsum[i] == 2)
                {
                    res[0].Add(1);
                    res[1].Add(1);
                }
                else if (colsum[i] == 1)
                {
                    if (upper > 0)
                    {
                        res[0].Add(1);
                        res[1].Add(0);
                        --upper;
                    }
                    else
                    {
                        res[0].Add(0);
                        res[1].Add(1);
                    }
                }
                else
                {
                    res[0].Add(0);
                    res[1].Add(0);
                }
            }
            return res;
        }


    }
}
