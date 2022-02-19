using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5998
{
    /*
     5998. 拆分成最多数目的偶整数之和 
给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的偶整数之和，且拆分出来的偶整数数目 最多 。

比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的偶整数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
请你返回一个整数数组，表示将整数拆分成 最多 数目的偶整数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。
     */
    public class Class5998
    {
        public IList<long> MaximumEvenSplit(long finalSum)
        {
            IList<long> res = new List<long>();
            if (finalSum % 2 != 0)
            {
                return res;
            }
            long cur = 2;
            while (finalSum >= cur)
            {
                if (finalSum - cur > cur)
                {
                    res.Add(cur);
                    finalSum -= cur;
                }
                else
                {
                    res.Add(finalSum);
                    finalSum = 0;
                }
                cur += 2;
            }

            return res;
        }
    }
}
