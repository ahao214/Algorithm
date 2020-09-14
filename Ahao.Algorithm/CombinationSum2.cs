using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 40.组合总和(二)
    /// </summary>
    public class CombinationSum2
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> Method(int[] candidates, int target)
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
                    //去掉重复的数据
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
