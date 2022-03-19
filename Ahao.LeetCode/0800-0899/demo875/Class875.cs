using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo875
{
    /// <summary>
    /// 875. 爱吃香蕉的珂珂
    /// </summary>
    public class Class875
    {
        public int MinEatingSpeed(int[] piles, int h)
        {
            int L = 1;
            int R = 0;
            foreach (var pile in piles)
            {
                R = Math.Max(pile, R);
            }
            int res = 0;
            int middle = 0;
            while (L <= R)
            {
                middle = L + ((R - L) >> 1);
                if (Hours(piles, middle) <= h)
                {
                    res = middle;
                    R = middle - 1;
                }
                else
                {
                    L = middle + 1;
                }
            }
            return res;
        }

        /// <summary>
        /// 以speed的速度吃完香蕉需要多久
        /// </summary>
        /// <param name="piles"></param>
        /// <param name="speed"></param>
        /// <returns></returns>
        private int Hours(int[] piles, int speed)
        {
            int res = 0;
            foreach (var pile in piles)
            {
                //向上取整
                res += (pile + speed - 1) / speed;
            }
            return res;
        }
    }
}
