using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 39.组合总和
    /// </summary>
    public class CombinationSum
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> Method(int[] candidates, int target)
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
