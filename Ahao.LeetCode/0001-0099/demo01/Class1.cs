using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    public class Class1
    {
        public int[] TwoSum(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                var nj = target - nums[i];
                //Array.IndexOf 方法从数组中查找指定对象的下标
                //nj 表示要查找的对象
                //i+1 表示查找的开始位置
                var j = Array.IndexOf(nums, nj, i + 1);
                if (j >= 0)
                {
                    return new[] { i, j };
                }
            }
            return Array.Empty<int>();
        }

        public int[] TwoSum2(int[] nums, int target)
        {
            var map = new Dictionary<int, int>(nums.Length);
            for (int i = 0; i < nums.Length; i++)
            {
                map[nums[i]] = i;
            }
            for (int i = 0; i < nums.Length; i++)
            {
                var nj = target - nums[i];
                if (map.ContainsKey(nj))
                {
                    var j = map[nj];
                    if (j > i)
                    {
                        return new[] { i, j };
                    }
                }
            }
            return Array.Empty<int>();
        }
    }
}
