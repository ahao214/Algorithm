using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 204.计算质数
    /// </summary>
    public class CountPrimes
    {
        public int Method(int n)
        {
            int result = 0;            
            bool[] IsPrimes = new bool[n];
            for (int i = 2; i < n; i++)//从2往后筛
            {
                if (!IsPrimes[i])
                {
                    result++;
                    for (int j = i + i; j < n; j += i)
                    {
                        //排除不是质数的值
                        IsPrimes[j] = true;
                    }
                }
            }
            return result;
        }
    }

}
