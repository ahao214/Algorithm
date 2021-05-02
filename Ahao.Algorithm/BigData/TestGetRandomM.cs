using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.BigData
{
    /// <summary>
    /// 如何等概率地从大小为n的数组中选取m个整数
    /// </summary>
    public class TestGetRandomM
    {
        public static void GetRandomM(int[] a, int n, int m)
        {
            if (a == null || n <= 0 || n < m)
            {
                Console.WriteLine("参数不合理");
                return;
            }

            int tmp;
            Random r = new Random();
            for (int i = 0; i < m; ++i)
            {
                int j = i + r.Next(n - 1);  //获取i到n-1间的随机数
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
