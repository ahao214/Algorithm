using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 进行数字的二进制翻转
    /// </summary>
    public class TestVal
    {
        public static int Val(int a, int b)
        {
            int m = a ^ b;
            int num = 0;
            while (m!=0)
            {
                m &= (m - 1);
                num++;
            }
            return num;

        }

    }
}
