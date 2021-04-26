using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1011. 在 D 天内送达包裹的能力
    /// </summary>
    public class ShipWithinDays
    {
        public int Method(int[] weights, int D)
        {
            int result = 0;
            int average;
            if (D == 1)
            {
                result = weights.Sum();
            }
            int sum = 0;
            int surplusWeight = weights.Sum();
            average = surplusWeight / D;         
            result = CountDays(weights, D, result, average, 0, surplusWeight);
            return result;
        }

       
        public int CountDays(int[] weight, int day, int result, int average, int tmp, int surplusWeight)
        {
            int sum = 0;

            for (int i = tmp; i < weight.Length; i++)
            {
                tmp = i;
                if (sum < average)
                {
                    sum += weight[i];
                }
                else
                {
                    day -= 1;
                    surplusWeight -= sum;

                    if (surplusWeight % day == 0)
                    {
                        result = sum;
                        break;
                    }
                    else
                    {
                        average = surplusWeight / day;
                        CountDays(weight, day, result, average, tmp, surplusWeight);
                    }
                }
            }

            return result;
        }
    }
}
