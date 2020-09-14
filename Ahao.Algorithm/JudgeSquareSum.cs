using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 633-平方数之和
    /// </summary>
    public class JudgeSquareSum
    {
        public bool Method(int c)
        {
            bool result = false;
            int a = Convert.ToInt32(Math.Sqrt(c));
            int b = 0;
            if (Math.Pow(a, 2) > int.MaxValue)
            {
                return result;
            }
            while (b <= a)
            {
                
                long total = Convert.ToInt32(Math.Pow(a, 2)) + Convert.ToInt32(Math.Pow(b, 2));
                if (total > c)
                {
                    a -= 1;
                }
                else if (total < c)
                {
                    b += 1;
                }
                else
                {
                    result = true;
                    break;
                }
            }

            return result;
        }
    }
}
