using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 78.子集
    /// </summary>
    public class Subsets
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> Method(int[] nums)
        {
            List<int> temp = new List<int>();            
            int start = 0;
            int len = nums.Length;
            Dfs(start, len, temp,nums);
            return result;           
        }

        public void Dfs(int start, int len, List<int> temp,int [] nums)
        {
            result.Add(new List<int>(temp));
            for (; start < len; start++)
            {
                temp.Add(nums[start]);
                Dfs(start + 1, len, temp,nums);
                temp.RemoveAt(temp.Count - 1);
            }
        }
    }
}
