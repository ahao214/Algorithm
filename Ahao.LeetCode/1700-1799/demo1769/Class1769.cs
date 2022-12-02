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



        public int[] MinOperations2(string boxes)
        {
            int left = boxes[0] - '0', right = 0, operations = 0;
            int n = boxes.Length;
            for (int i = 1; i < n; i++)
            {
                if (boxes[i] == '1')
                {
                    right++;
                    operations += i;
                }
            }
            int[] res = new int[n];
            res[0] = operations;
            for (int i = 1; i < n; i++)
            {
                operations += left - right;
                if (boxes[i] == '1')
                {
                    left++;
                    right--;
                }
                res[i] = operations;
            }
            return res;
        }

    }
}
