using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo517
{
    public class Class517
    {
        public int FindMinMoves(int[] machines)
        {
            if (machines == null || machines.Length == 0)
                return 0;
            int size = machines.Length;
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += machines[i];

            if (sum % size != 0)
                return -1;
            int avg = sum / size;
            int leftSum = 0;
            int ans = 0;

            for (int i = 0; i < size; i++)
            {
                int leftRest = leftSum - i * avg;
                int rightRest = (sum - leftSum - machines[i]) - (size - i - 1) * avg;
                if (leftRest < 0 && rightRest < 0)
                {
                    ans = Math.Max(ans, Math.Abs(leftRest) + Math.Abs(rightRest));
                }
                else
                {
                    ans = Math.Max(ans, Math.Max(Math.Abs(leftRest), Math.Abs(rightRest)));
                }
                leftSum += machines[i];
            }
            return ans;
        }
    }
}
