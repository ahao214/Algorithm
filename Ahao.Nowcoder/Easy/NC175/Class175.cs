using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC175
{
    /// <summary>
    /// NC175 整数反转
    /// </summary>
    public class Class175
    {
        public int reverse(int num)
        {
            long result = 0;
            while (num != 0)
            {
                result = result * 10 + num % 10;
                num = num / 10;
            }
            if ((int)result != result)
            {
                return 0;
            }
            return (int)result;
        }
    }
}
