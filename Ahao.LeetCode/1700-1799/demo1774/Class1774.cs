using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1774
{
    public class Class1774
    {

        int res;

        public int ClosestCost(int[] baseCosts, int[] toppingCosts, int target)
        {
            res = baseCosts.Min();
            foreach (int b in baseCosts)
            {
                DFS(toppingCosts, 0, b, target);
            }
            return res;
        }

        public void DFS(int[] toppingCosts, int p, int curCost, int target)
        {
            if (Math.Abs(res - target) < curCost - target)
            {
                return;
            }
            else if (Math.Abs(res - target) >= Math.Abs(curCost - target))
            {
                if (Math.Abs(res - target) > Math.Abs(curCost - target))
                {
                    res = curCost;
                }
                else
                {
                    res = Math.Min(res, curCost);
                }
            }
            if (p == toppingCosts.Length)
            {
                return;
            }
            DFS(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, target);
            DFS(toppingCosts, p + 1, curCost + toppingCosts[p], target);
            DFS(toppingCosts, p + 1, curCost, target);
        }



        public int ClosestCost2(int[] baseCosts, int[] toppingCosts, int target)
        {
            int x = baseCosts.Min();
            if (x >= target)
            {
                return x;
            }
            bool[] can = new bool[target + 1];
            int res = 2 * target - x;
            foreach (int b in baseCosts)
            {
                if (b <= target)
                {
                    can[b] = true;
                }
                else
                {
                    res = Math.Min(res, b);
                }
            }
            foreach (int t in toppingCosts)
            {
                for (int count = 0; count < 2; ++count)
                {
                    for (int i = target; i > 0; --i)
                    {
                        if (can[i] && i + t > target)
                        {
                            res = Math.Min(res, i + t);
                        }
                        if (i - t > 0)
                        {
                            can[i] = can[i] | can[i - t];
                        }
                    }
                }
            }
            for (int i = 0; i <= res - target; ++i)
            {
                if (can[target - i])
                {
                    return target - i;
                }
            }
            return res;
        }

    }
}
