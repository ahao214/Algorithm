using System;
using static System.Console;


namespace ch01_01
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine($"5!={Fac(5)}");
            ReadKey();
        }

        /// <summary>
        /// 阶乘函数
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        static int Fac(int n)
        {
            if (n == 0)
                return 1;
            else
                return n * Fac(n - 1);
        }

    }
}
