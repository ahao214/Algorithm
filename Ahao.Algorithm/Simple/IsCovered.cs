using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1893. 检查是否区域内所有整数都被覆盖
    /// </summary>
    public class IsCovered
    {
        public bool Method(int[][] ranges, int left, int right)
        {
            int[] diff = new int[52];
            foreach (int[] range in ranges)
            {
                diff[range[0]]++;
                diff[range[1] + 1]--;
            }

            int sum = 0;
            for (int i = 0; i <= 50; i++)
            {
                sum += diff[i];
                if (i >= left && i <= right && sum <= 0)
                {
                    return false;
                }
            }
            return true;
        }

    }
}
