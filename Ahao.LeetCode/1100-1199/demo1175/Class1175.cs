using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1175
{
    public class Class1175
    {
        const int MOD = 1000000007;

        public int NumPrimeArrangements(int n)
        {
            int numPrimes = 0;
            for (int i = 1; i <= n; i++)
            {
                if (IsPrime(i))
                {
                    numPrimes++;
                }
            }
            return (int)(Factorial(numPrimes) * Factorial(n - numPrimes) % MOD);
        }

        public bool IsPrime(int n)
        {
            if (n == 1)
            {
                return false;
            }
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        public long Factorial(int n)
        {
            long res = 1;
            for (int i = 1; i <= n; i++)
            {
                res *= i;
                res %= MOD;
            }
            return res;
        }

    }
}
