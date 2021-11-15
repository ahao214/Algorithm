using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 229. 求众数 II
    /// </summary>
    public class MajorityElement
    {
        public IList<int> Method(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(nums[i]))
                {
                    dic[nums[i]]++;
                }
                else
                {
                    dic.Add(nums[i], 1);
                }
            }
            IList<int> res = new List<int>();
            foreach (KeyValuePair<int, int> pair in dic)
            {
                if (pair.Value > nums.Length / 3)
                {
                    res.Add(pair.Key);
                }
            }
            return res;
        }
    }
}
