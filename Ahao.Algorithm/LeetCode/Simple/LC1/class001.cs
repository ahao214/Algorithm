using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple.LC1
{
    /// <summary>
    /// 1.两数之和
    /// </summary>
    public class class001
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int[] result = Array.Empty<int>();
            if (nums == null || nums.Length == 0)
                return result;
            for (int i = 0; i < nums.Length; i++)
            {
                var nj = target - nums[i];
                //Array.IndexOf 方法从数组中查找指定对象的下标
                var j = Array.IndexOf(nums, nj, i + 1);
                if (j >= 0)
                    return new[] { i, j };
            }
            return result;
        }
    }
}
