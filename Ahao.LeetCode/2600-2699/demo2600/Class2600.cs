using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2600
{
    public class Class2600
    {

        public int KItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
        {
            if (k <= numOnes)
            {
                return k;
            }
            else if (k <= numOnes + numZeros)
            {
                return numOnes;
            }
            else
            {
                return numOnes - (k - numOnes - numZeros);
            }
        }

    }
}
