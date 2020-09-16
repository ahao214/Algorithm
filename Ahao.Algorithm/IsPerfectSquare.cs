using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 367. 有效的完全平方数
    /// </summary>
    public class IsPerfectSquare
    {
        public bool Method(int num)
        {
            long square = 0;            
            while(true)
            {
                long value = square * square;              
                if (value > num)
                {
                    return false;
                }
                if (value == num)
                {
                    return true;
                }
                square++;
            }
            return false;
        }
    }
}
