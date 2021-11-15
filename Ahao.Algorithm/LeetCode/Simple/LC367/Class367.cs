using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple.LC367
{
    /// <summary>
    /// 367. 有效的完全平方数
    /// </summary>
    public class Class367
    {
        public bool IsPerfectSquare(int num)
        {
            long square = 0;
            while (true)
            {
                long value = square * square;
                if (value > num)
                {
                    return false;
                }
                if (value == num)
                {
                    return true;
                }
                square++;
            }
            return false;
        }

        public bool IsPerfectSquare2(int num)
        {
            int low = 0;
            int high = num;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                long square = (long)mid * mid;
                if (square == num)
                {
                    return true;
                }
                else if (square < num)
                {
                    low = low + 1;
                }
                else
                {
                    high = high - 1;
                }
            }
            return false;
        }
    }
}
