using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 219.存在重复元素(2)
    /// </summary>
    public class ContainsNearbyDuplicate
    {
        public bool Method(int[] nums, int k)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            bool result = false;
            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(nums[i]))
                {
                    if (i - dic[nums[i]] <= k)
                    {
                        result = true;
                        break;
                    }
                    dic[nums[i]] = i;
                }
                else
                {
                    dic[nums[i]] = i;
                }
            }
            return result;
        }
    }
}
