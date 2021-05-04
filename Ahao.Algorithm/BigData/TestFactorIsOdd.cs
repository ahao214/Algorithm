using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.BigData
{
    /// <summary>
    /// 如何判断还有几盏灯泡亮着
    /// </summary>
    public class TestFactorIsOdd
    {
        public static int FactorIsOdd(int a)
        {
            int total = 0;
            int i;
            for (i = 1; i <= a; i++)
            {
                if (a % i == 0)
                    total++;
            }
            if (total % 2 == 1)
                return 1;
            else
                return 0;
        }

        public static int TotalCount(int[] num, int n)
        {
            int i;
            int count = 0;
            for (i = 0; i < n; i++)
            {
                //判断因子数是否为奇数，如果是奇数(灯亮)则加1
                if (FactorIsOdd(num[i]) == 1)
                {
                    Console.WriteLine("亮着的灯的编号是：" + num[i]);
                    count++;
                }
            }
            return count;
        }

    }
}
