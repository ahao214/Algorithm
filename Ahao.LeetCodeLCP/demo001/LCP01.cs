using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCodeLCP
{
    public class LCP01
    {
        /// <summary>
        /// LCP 01. 猜数字
        /// </summary>
        /// <param name="guess"></param>
        /// <param name="answer"></param>
        /// <returns></returns>
        public int Game(int[] guess, int[] answer)
        {
            int count = 0;
            for (int i = 0; i < 3; i++)
                count += guess[i] == answer[i] ? 1 : 0;
            return count;
        }
    }
}
