using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ65
{
    /// <summary>
    /// JZ65 不用加减乘除做加法
    /// </summary>
    public class Add
    {
        public int Method(int num1, int num2)
        {
            if (num1 == 0 & num2 == 0)
            {
                return 0;
            }
            else if (num1 == 0)
            {
                return num2;
            }
            else if (num2 == 0)
            {
                return num1;
            }
            if (num1 > num2)
            {
                return (num1 * num1 - num2 * num2) / (num1 - num2);
            }
            return (num2 * num2 - num1 * num1) / (num2 - num1);
        }
    }
}
