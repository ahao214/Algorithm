using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo846
{
    /// <summary>
    /// 846. 一手顺子
    /// </summary>
    public class Class846
    {
        /*
Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，
并且由 groupSize 张连续的牌组成。
给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。
如果她可能重新排列这些牌，返回 true ；否则，返回 false 。
*/
        public bool IsNStraightHand(int[] hand, int groupSize)
        {
            int n = hand.Length;
            if (n % groupSize != 0)
            {
                return false;
            }
            Array.Sort(hand);
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var h in hand)
            {
                if (!dic.ContainsKey(h))
                {
                    dic.Add(h, 0);
                }
                dic[h]++;
            }

            foreach (int x in hand)
            {
                if (!dic.ContainsKey(x))
                {
                    continue;
                }
                for (int i = 0; i < groupSize; i++)
                {
                    int res = x + i;
                    if (!dic.ContainsKey(res))
                    {
                        return false;
                    }
                    dic[res]--;
                    if (dic[res] == 0)
                    {
                        dic.Remove(res);
                    }
                }
            }
            return true;
        }
    }
}
