using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1769
{
    public class Class1769
    {

        public int[] MinOperations(string boxes)
        {
            int n = boxes.Length;
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
            {
                int sm = 0;
                for (int j = 0; j < n; j++)
                {
                    if (boxes[j] == '1')
                    {
                        sm += Math.Abs(j - i);
                    }
                }
                res[i] = sm;
            }
            return res;
        }

    }
}
