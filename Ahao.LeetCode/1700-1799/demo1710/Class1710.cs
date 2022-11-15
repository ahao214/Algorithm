using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1710
{
    public class Class1710
    {
        public int MaximumUnits(int[][] boxTypes, int truckSize)
        {
            Array.Sort(boxTypes, (a, b) => b[1] - a[1]);
            int res = 0;
            foreach (int[] boxType in boxTypes)
            {
                int numberOfBoxes = boxType[0];
                int numberOfUnitsPerBox = boxType[1];
                if (numberOfBoxes < truckSize)
                {
                    res += numberOfBoxes * numberOfUnitsPerBox;
                    truckSize -= numberOfBoxes;
                }
                else
                {
                    res += truckSize * numberOfUnitsPerBox;
                    break;
                }
            }
            return res;
        }

    }
}
