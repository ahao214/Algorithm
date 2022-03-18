using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo39
{
    /*
     39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
     */
    public class Class39
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> CombinationSum(int[] candidates, int target)
        {
            Array.Sort(candidates);
            recrusion(candidates, 0, target, new List<int>(target), result);
            return result;
        }
        private void recrusion(int[] candidates, int start, int target, IList<int> item, IList<IList<int>> result)
        {
            if (target == 0)
            {
                result.Add(item.ToList());
            }
            if (target > 0)
            {
                for (var i = start; i < candidates.Length; i++)
                {
                    if (candidates[i] <= target)
                    {
                        item.Add(candidates[i]);
                        recrusion(candidates, i, target - candidates[i], item, result);
                        item.RemoveAt(item.Count() - 1);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}
