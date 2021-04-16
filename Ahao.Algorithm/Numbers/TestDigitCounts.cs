using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 查找连续数字中某个数字出现的次数
    /// </summary>
    public class TestDigitCounts
    {
        public static int DigitCounts(int k, int n)
        {
            int result = 0;
            int baseLine = 1;
            while (n / baseLine > 0)
            {
                int cur = (n / baseLine) % 10;
                int low = n - (n / baseLine) * baseLine;
                int high = n / (baseLine * 10);

                if (cur == k)
                {
                    result += high * baseLine + low + 1;
                }
                else if (cur < k)
                {
                    result += high * baseLine;
                }
                else
                {
                    result += (high + 1) * baseLine;
                }
                baseLine *= 10;
            }
            return result;
        }
    }
}
