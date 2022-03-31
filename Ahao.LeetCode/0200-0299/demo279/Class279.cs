using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo279
{
    public class Class279
    {
        public int NumSquares(int n)
        {
            int rest = n;
            while (rest % 4 == 0)
                rest /= 4;
            if (rest % 8 == 0)
                return 4;
            int f = (int)Math.Sqrt(n);
            if (f * f == n)
                return 1;
            for (int first = 1; first * first <= n; first++)
            {
                int second = (int)Math.Sqrt(n - first * first);
                if (first * first + second * second == 0)
                    return 2;
            }
            return 3;
        }


        public int NumSquares2(int n)
        {
            int res = n, num = 2;
            while (num * num <= n)
            {
                int a = n / (num * num), b = n % (num * num);
                res = Math.Min(res, a + nSquare(b));
                num++;
            }
            return res;
        }


        public int nSquare(int n)
        {
            while (n % 4 == 0)
            {
                n /= 4;
            }
            if (n % 8 == 0)
                return 4;
            for (int a = 0; a * a <= n; a++)
            {
                int b = (int)Math.Sqrt(n - a * a);
                if (a * a + b * b == n)
                    return (a > 0 && b > 0) ? 2 : 1;
            }
            return 3;
        }

    }
}
