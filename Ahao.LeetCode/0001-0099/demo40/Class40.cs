using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo40
{
    /*
     40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 
     */
    public class Class40
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> CombinationSum2(int[] candidates, int target)
        {
            Array.Sort(candidates);
            recrusion(candidates, target, 0, new List<int>(), 0);
            return result;
        }

        private void recrusion(int[] candidates, int target, int sum, IList<int> item, int begin)
        {
            if (sum == target)
            {
                result.Add(new List<int>(item));
                return;
            }
            for (int i = begin; i < candidates.Length; i++)
            {
                if (sum < target)
                {
                    if (i > begin && candidates[i] == candidates[i - 1]) continue;
                    sum += candidates[i];
                    item.Add(candidates[i]);
                    recrusion(candidates, target, sum, item, i + 1);
                    sum -= candidates[i];
                    item.RemoveAt(item.Count - 1);
                }
            }
        }

    }
}
