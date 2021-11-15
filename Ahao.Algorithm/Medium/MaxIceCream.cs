using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1833. 雪糕的最大数量
    /// </summary>
    public class MaxIceCream
    {
        public int Method(int []costs ,int coins)
        {
            Array.Sort(costs);
            int result = 0;
            for(int i=0;i<costs.Length;i++)
            {
                int cost = costs[i];
                if(cost <=coins)
                {
                    coins -= cost;
                    result++;
                }
                else
                {
                    break;
                }
            }
            return result;
        }

    }
}
