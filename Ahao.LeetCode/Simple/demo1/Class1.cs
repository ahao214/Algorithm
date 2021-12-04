using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1
{
    /// <summary>
    /// 1. 两数之和
    /// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    ///你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    ///你可以按任意顺序返回答案。
    /// </summary>
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
