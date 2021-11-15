using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 342.4的幂
    /// </summary>
    public class IsPowerOfFour
    {
        public bool Method(int num)
        {
            if (num == 1 || num == 4)
            {
                return true;
            }

            while (num != 1)
            {
                if (num % 4 != 0)
                {
                    return false;
                }
                num = num / 4;
            }
            return true;
        }
    }
}
