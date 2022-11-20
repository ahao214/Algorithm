using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo799
{
    public class Class799
    {
        public double ChampagneTower(int poured, int query_row, int query_glass)
        {
            double[] row = { poured };
            for (int i = 1; i <= query_row; i++)
            {
                double[] nextRow = new double[i + 1];
                for (int j = 0; j < i; j++)
                {
                    double volume = row[j];
                    if (volume > 1)
                    {
                        nextRow[j] += (volume - 1) / 2;
                        nextRow[j + 1] += (volume - 1) / 2;
                    }
                }
                row = nextRow;
            }
            return Math.Min(1, row[query_glass]);
        }

    }
}
