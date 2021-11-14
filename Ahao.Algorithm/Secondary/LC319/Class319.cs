using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 319. 灯泡开关
    /// </summary>
    public class Class319
    {
        public int BulbSwitch(int n)
        {
            return (int)Math.Sqrt(n + 0.5);
        }

        public int BulbSwitch2(int n)
        {
            if (n == 1)
            {
                return 1;
            }
            int result = 1;
            while (true)
            {
                if (result * result > n)
                {
                    break;
                }
                result++;
            }
            return result - 1;
        }
    }
}
