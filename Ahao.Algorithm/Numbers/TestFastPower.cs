using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 进行指数运算
    /// </summary>
    public class TestFastPower
    {
        public static int FastPower(int a, int b, int n)
        {
            if (n == 0)
            {
                return 1 % b;
            }
            else if (n == 1)
            {
                return a % b;
            }

            long product = FastPower(a, b, n / 2);
            product = product * product % b;

            if (n % 2 == 1)
            {
                product = (product * (a % b)) % b;
            }
            return (int)product;
        }
    }
}
