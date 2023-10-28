using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo277
{
    public class Class277
    {
        public int findCelebrity(int n)
        {
            int cand = 0;   //谁可能成为明星，谁就是cand
            for (int i = 0; i < n; i++)
            {
                if (knows(cand, i))
                    cand = i;
            }

            for (int i = 0; i < cand; i++)
            {
                if (knows(cand, i))
                    return -1;
            }
            //是不是所有的人都认识cand
            for (int i = 0; i < n; i++)
            {
                if (!knows(i, cand))
                    return -1;
            }
            return cand;
        }

        public bool knows(int x, int y)
        {
            return true;
        }
    }
}
