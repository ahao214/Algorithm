using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2100_2199.demo2178
{
    public class Class2178
    {

        public List<long> MaximumEvenSplit(long finalSum)
        {
            List<long> res = new List<long>();
            if (finalSum % 2 > 0)
            {
                return res;
            }
            for (int i = 2; i <= finalSum; i += 2)
            {
                res.Add(i);
                finalSum -= i;
            }
            res[res.Count - 1] += finalSum;
            return res;
        }

    }
}
