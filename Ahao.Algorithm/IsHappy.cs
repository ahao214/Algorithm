using System.Collections.Generic;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 202.快乐数
    /// </summary>
    public  class IsHappy
    {
        public bool Method(int n)
        {
            HashSet<int> seen = new HashSet<int>();
            while (n != 1 && !seen.Contains(n))
            {
                seen.Add(n);
                n = getSum(n);
            }
            return n == 1;
        }

        private int getSum(int n)
        {
            int totalSum = 0;
            while (n > 0)
            {
                int d = n % 10;
                n = n / 10;
                totalSum += d * d;
            }
            return totalSum;
        }
    }
}
