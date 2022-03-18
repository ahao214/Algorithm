using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5194
{
    /*
     * 5194. 得到目标值的最少行动次数
     你正在玩一个整数游戏。从整数 1 开始，期望得到整数 target 。

在一次行动中，你可以做下述两种操作之一：

递增，将当前整数的值加 1（即， x = x + 1）。
加倍，使当前整数的值翻倍（即，x = 2 * x）。
在整个游戏过程中，你可以使用 递增 操作 任意 次数。但是只能使用 加倍 操作 至多 maxDoubles 次。

给你两个整数 target 和 maxDoubles ，返回从 1 开始得到 target 需要的最少行动次数。
     
     */
    public class Class5194
    {
        public int MinMoves(int target, int maxDoubles)
        {
            if (maxDoubles == 0)
            {
                return target - 1;
            }

            int count = 0;
            int tmp = target;
            while (maxDoubles != 0 && tmp != 1)
            {
                if (tmp % 2 == 0)
                {
                    count++;
                    maxDoubles--;
                    tmp /= 2;
                }
                else
                {
                    count++;
                    tmp--;
                }
            }
            if (maxDoubles == 0 && tmp != 1)
            {
                count += tmp - 1;
            }
            return count;
        }

        public int MinMoves1(int target, int maxDoubles)
        {
            int res = 0;
            while (target > 1)
            {
                if (maxDoubles > 0)
                {
                    if (target % 2 == 1)
                    {
                        res += 1;
                        target -= 1;
                    }
                    res += 1;
                    maxDoubles -= 1;
                    target /= 2;
                }
                else
                {
                    res += target - 1;
                    break;
                }
            }
            return res;
        }
    }
}
